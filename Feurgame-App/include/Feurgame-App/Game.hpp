#pragma once

#include <Feurgame-GUILib/Layout.hpp>
#include <Feurgame-Lib/Display.hpp>
#include <Feurgame-Lib/Game.hpp>

#include <Feurgame-App/Widgets/MapView.hpp>

class GameLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;

    map_view_ptr map_view_;
public:
    GameLayout(window_ptr window) : Layout(window) {}
    ~GameLayout() = default;
    
    void init() override {
        Game* game = Game::get_instance();
        int a = 1;
        widgets_["bar"] = new BarDisplay<int>(std::make_shared<int>(a));
        widgets_["detail"] = new DetailDisplay<int>(std::make_shared<int>(a));

        MapViewer* map_viewer = new MapViewer(game->get_map_config());
        widgets_["map"] = map_viewer;

        map_view_ = std::make_shared<MapView>(*map_viewer);

        window_->setView(*map_view_);
    }

    map_view_ptr get_map_view() const;
    void update_map_view() const;
};

class GameEventHandler : public EventHandler {
private:
    std::shared_ptr<GameLayout> game_layout_;
public:
    // TODO: find a way to improve this
    GameEventHandler(std::shared_ptr<GameLayout> layout) :
        EventHandler(layout),
        game_layout_(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
    void handle(const sf::Event::TextEntered& event) override;
};
