#pragma once

#include <Feurgame-GUILib/Layout.hpp>
#include <Feurgame-Lib/Display.hpp>
#include <Feurgame-Lib/Game.hpp>

#include "Widgets/Buttons.hpp"
#include "Widgets/MapViewer.hpp"
#include "Widgets/Pawn.hpp"

using view_ptr = std::shared_ptr<sf::View>;

class GameLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;

    view_ptr map_view_;
public:
    GameLayout(window_ptr window) : Layout(window) {}
    ~GameLayout() = default;
    
    void init() override {
        Game* game = Game::get_instance();

        MapViewer* map_viewer = new MapViewer(game->get_map_config());
        widgets_["_map"] = map_viewer;

        map_view_ = std::make_shared<sf::View>(sf::Vector2f{ WINDOW_X / 2, WINDOW_Y / 2}, map_viewer->getShape().getSize());
        map_view_->setViewport(sf::FloatRect({0.f, 0.f}, {1.f, 1.f}));
        window_->setView(*map_view_);

        int a = 1;  // temp
        widgets_["bar"] = new BarDisplay<int>(window_, std::make_shared<int>(a));
        widgets_["detail"] = new DetailDisplay<int>(window_, std::make_shared<int>(a));

        ListWidget* cities = new ListWidget({0, 0}, {});
        ListWidget* armies = new ListWidget({0, 0}, {});

        for (region_ptr r : game->get_map()->get_regions())
            cities->addWidget(new CityPawnWidget(r->get_city()));

        for (army_ptr a : game->get_map()->get_armies())
            armies->addWidget(new ArmyPawnWidget(a));
        
        widgets_["cities"] = cities;
        widgets_["armies"] = armies;
    }

    view_ptr get_map_view() const;
    void update_map_view() const;
};

class GameEventHandler : public EventHandler {
private:
    std::shared_ptr<GameLayout> game_layout_;
public:
    // TODO: find a way to improve this
    GameEventHandler(std::shared_ptr<GameLayout> layout) : EventHandler(layout), game_layout_(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
    void handle(const sf::Event::TextEntered& event) override;
};
