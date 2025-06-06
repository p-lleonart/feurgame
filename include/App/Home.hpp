#pragma once

#include "Lib/Layout.hpp"

#include "App/Widgets/Logo.hpp"
#include "App/Widgets/Buttons.hpp"

class HomeLayout : public Layout {
protected:
    BaseEventHandler* getEventHandler() override;
public:
    HomeLayout(sf::RenderWindow& window) : Layout(window) {
        this->widgets_["logo"] = new LogoWidget();
        this->widgets_["play_btn"] = new HomePlayButtonWidget();
    }
    ~HomeLayout() = default;
};

class HomeEventHandler : public EventHandler {
private:
public:
    HomeEventHandler(Layout& layout) : EventHandler(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
};
