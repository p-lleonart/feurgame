#pragma once

#include <Feurgame-GUILib/Layout.hpp>

#include "Widgets/Texts.hpp"
#include "Widgets/Buttons.hpp"

class PlayersFormLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;
public:
    PlayersFormLayout(window_ptr window) : Layout(window) {
        this->widgets_["player_names_inputs"] = new ListWidget(
            {10, 10},
            {new PlayerNameTextWidget({0, 0})}
        );
        this->widgets_["submit_btn"] = new PlayerFormSubmitButtonWidget();
    };
    ~PlayersFormLayout() = default;
};

class PlayersFormEventHandler : public EventHandler {
protected:
    int current_text_widget_ = 0;
public:
    PlayersFormEventHandler(layout_ptr layout) : EventHandler(layout) {};

    void handle(const sf::Event::TextEntered& event) override;
    void handle(const sf::Event::KeyPressed& event) override;
    void handle(const sf::Event::MouseButtonPressed& event) override;
};
