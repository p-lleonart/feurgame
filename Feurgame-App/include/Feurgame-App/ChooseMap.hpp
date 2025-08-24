#pragma once

#include <Feurgame-GUILib/Layout.hpp>

#include "Widgets/Buttons.hpp"

class ChooseMapButtonWidget : public ButtonWidget {
public:
    ChooseMapButtonWidget(std::string map_path, sf::Vector2f pos) : ButtonWidget(map_path, {}, false) {
        this->pos_ = pos;
        this->sprite_->setPosition(this->pos_);
        this->sprite_->scale({ 0.25, 0.25 });
    }
    ~ChooseMapButtonWidget() = default;

    void callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout);
};

class ChooseMapLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;
public:
    ChooseMapLayout(window_ptr window) : Layout(window) {}
    ~ChooseMapLayout() = default;

    void init() override {
        this->widgets_["title"] = new TextWidget(
            TextBackgroundWidget::mk_unique(sf::Vector2f{10, 10}, sf::Vector2f{ 300, 40 }),
            "choose your map"
        );
        
        // get all available maps for n players.
        
        this->widgets_["maps"] = new ListWidget({10, 60}, {
            new ChooseMapButtonWidget("assets/maps/test/map3v3.png", {10, 10})
        });
    }
};

class ChooseMapEventHandler : public EventHandler {
private:
public:
    ChooseMapEventHandler(layout_ptr layout) : EventHandler(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
};
