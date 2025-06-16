#pragma once

#include "Lib/Layout.hpp"

#include "App/Widgets/Logo.hpp"
#include "App/Widgets/Buttons.hpp"

class HomeLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;
public:
    HomeLayout(window_ptr window) : Layout(window) {
        this->widgets_["logo"] = new LogoWidget();
        this->widgets_["play_btn"] = new HomePlayButtonWidget();
    }
    ~HomeLayout() = default;
};

class HomeEventHandler : public EventHandler {
private:
public:
    HomeEventHandler(layout_ptr layout) : EventHandler(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
};
