#pragma once

#include "Lib/Layout.hpp"
#include "App/Widgets/Texts.hpp"
#include "App/Widgets/Buttons.hpp"

class PlayersFormLayout : public Layout {
protected:
    BaseEventHandler* getEventHandler() override;
public:
    PlayersFormLayout(sf::RenderWindow* window);
};

class PlayersFormEventHandler : public EventHandler {
protected:
    int current_text_widget_ = 0;
public:
    PlayersFormEventHandler(Layout& layout) : EventHandler(layout) {};

    void handle(const sf::Event::TextEntered& event) override;
    void handle(const sf::Event::KeyPressed& event) override;
    void handle(const sf::Event::MouseButtonPressed& event) override;
};
