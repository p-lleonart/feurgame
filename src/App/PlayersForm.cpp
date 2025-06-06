#include "App/PlayersForm.hpp"

BaseEventHandler* PlayersFormLayout::getEventHandler() {
    if (!this->event_handler_)
        this->event_handler_ = new PlayersFormEventHandler(*this);

    return this->event_handler_;
}

PlayersFormLayout::PlayersFormLayout(sf::RenderWindow* window) {
    this->widgets_["player_names_inputs"] = new ListWidget(
        {10, 10},
        {
            new PlayerNameTextWidget({0, 0}),
            new PlayerNameTextWidget({0, 50}),
            new PlayerNameTextWidget({0, 100})
        }
    );
    this->widgets_["submit_btn"] = new PlayerFormSubmitButtonWidget();
    this->window_ = window;
}

void PlayersFormEventHandler::handle(const sf::Event::TextEntered& event) {
    if (this->current_text_widget_ >= this->layout_.getWidget<ListWidget>("player_names_inputs")->size()) return;

    if (!std::isprint(event.unicode)) return;

    PlayerNameTextWidget* text_widget = this->layout_.getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);

    std::string text = text_widget->getText();
    text.push_back((char) event.unicode);
    text_widget->setText(text);
}

void PlayersFormEventHandler::handle(const sf::Event::KeyPressed& event) {
    if (this->current_text_widget_ >= this->layout_.getWidget<ListWidget>("player_names_inputs")->size()) return;
    
    PlayerNameTextWidget* text_widget = this->layout_.getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);
    
    std::string text = text_widget->getText();

    if (event.code == sf::Keyboard::Key::Enter && !text.empty())
        this->current_text_widget_++;
    else if (event.code == sf::Keyboard::Key::Backspace && !text.empty()) {
        text.pop_back();
        text_widget->setText(text);
    }
}

void PlayersFormEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    PlayerFormSubmitButtonWidget* btn = this->layout_.getWidget<PlayerFormSubmitButtonWidget>("submit_btn");

    if (event.button == sf::Mouse::Button::Left
        && btn->button_clicked(event.position)) {
            std::cout << "choose map layout" << std::endl; // will be implemented after the map parser
    }
}
