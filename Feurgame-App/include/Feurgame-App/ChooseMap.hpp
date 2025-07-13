#pragma once

#include <Feurgame-GUILib/Layout.hpp>

#include "Widgets/Buttons.hpp"

class ChooseMapLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;
public:
    ChooseMapLayout(window_ptr window) : Layout(window) {
        this->widgets_["title"] = new TextWidget(
            std::make_unique<TextBackgroundWidget>(sf::Vector2f{10, 10}, sf::Vector2f{ 300, 40 }),
            "choose your map"
        );
        
        // get all available maps for n players.
        
        this->widgets_["maps"] = new ListWidget({10, 60}, {
            new ChooseMapButtonWidget("assets/maps/test/map3v3.png", {10, 10})
        });
    }
    ~ChooseMapLayout() = default;
};

class ChooseMapEventHandler : public EventHandler {
private:
public:
    ChooseMapEventHandler(layout_ptr layout) : EventHandler(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
};
