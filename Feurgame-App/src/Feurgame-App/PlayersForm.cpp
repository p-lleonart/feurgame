#include <Feurgame-App/PlayersForm.hpp>

bool _validate_all_inputs(ListWidget* list) {
    for (int i = 0; i < list->size(); i++) {
        if (list->getWidget<PlayerNameTextWidget>(i)->getText() == "") return false;
    }
    return true;
}

void PlayerFormSubmitButtonWidget::callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout) {
    ListWidget* list = layout->getWidget<ListWidget>("player_names_inputs");
    if(!_validate_all_inputs(list)) return;

    std::cout << "choose map layout" << std::endl;
    current_layout = "choose_map";
    for (int i = 0; i < list->size(); i++)
        ChoosePlayerLayout::PLAYERS_NAMES.push_back(
            list->getWidget<TextWidget>(i)->getText()
        );
}

base_event_handler_ptr PlayersFormLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<PlayersFormEventHandler>(std::shared_ptr<Layout>(this));
    return event_handler_;
}

void PlayersFormEventHandler::handle(const sf::Event::TextEntered& event) {
    if (this->current_text_widget_ >= this->getWidget<ListWidget>("player_names_inputs")->size()) return;

    if (!std::isprint(event.unicode)) return;

    auto text_widget = this
        ->getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);

    std::string text = text_widget->getText();
    text.push_back((char) event.unicode);
    text_widget->setText(text);
}

void PlayersFormEventHandler::handle(const sf::Event::KeyPressed& event) {
    if (current_text_widget_ >= getWidget<ListWidget>("player_names_inputs")->size()) return;
    
    auto text_widget = getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);
    
    std::string text = text_widget->getText();

    if (event.code == sf::Keyboard::Key::Enter && !text.empty()) {
        current_text_widget_++;
        
        if (current_text_widget_ < 4)  // 4 is the max number of players yet
            getWidget<ListWidget>("player_names_inputs")->addWidget(
                new PlayerNameTextWidget({0, (float) current_text_widget_ * 50})
            );
    }
    else if (event.code == sf::Keyboard::Key::Backspace && !text.empty()) {
        text.pop_back();
        text_widget->setText(text);
    }
}

void PlayersFormEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    auto btn = getWidget<PlayerFormSubmitButtonWidget>("submit_btn");
    btn->process_callback(event, layout_, current_layout);
}
