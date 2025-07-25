#include <SFML/Graphics.hpp>

#include <Feurgame-GUILib/LayoutHandler.hpp>

#include <Feurgame-App/ChooseMap.hpp>
#include <Feurgame-App/ChoosePlayer.hpp>
#include <Feurgame-App/Game.hpp>
#include <Feurgame-App/Home.hpp>
#include <Feurgame-App/PlayersForm.hpp>

int main() {
    window_ptr window = std::make_shared<sf::RenderWindow>(sf::VideoMode({WINDOW_X, WINDOW_Y}), "FeurGame");
    window->setFramerateLimit(144);
    
    LayoutHandler layout_handler;
    layout_handler.add("choose_map", new ChooseMapLayout(window));
    layout_handler.add("choose_player", new ChoosePlayerLayout(window));
    layout_handler.add("game", new GameLayout(window));
    layout_handler.add("home", new HomeLayout(window));
    layout_handler.add("players_form", new PlayersFormLayout(window));
    layout_handler.changeCurrent("home");

    while (window->isOpen()) {
        // events
        std::string new_layout = layout_handler.getCurrent()->handleEvents(layout_handler.getCurrentKey());

        if (new_layout != layout_handler.getCurrentKey())
            layout_handler.changeCurrent(new_layout);

        // updates
        layout_handler.getCurrent()->update();

        // display
        window->clear();
        layout_handler.getCurrent()->display();
        window->display();
    }

    return 0;
}
