#include <SFML/Graphics.hpp>

#include "Lib/LayoutHandler.hpp"

#include "App/ChooseMap.hpp"
#include "App/Home.hpp"
#include "App/PlayersForm.hpp"

int main() {
    window_ptr window = std::make_shared<sf::RenderWindow>(sf::VideoMode({640u, 480u}), "FeurGame");
    window->setFramerateLimit(144);
    
    LayoutHandler layout_handler;
    layout_handler.add("choose_map", new ChooseMapLayout(window));
    layout_handler.add("home", new HomeLayout(window));
    layout_handler.add("players_form", new PlayersFormLayout(window));
    layout_handler.changeCurrent("home");

    while (window->isOpen()) {
        // events
        layout_handler.changeCurrent(
            layout_handler.getCurrent()->handleEvents(layout_handler.getCurrentKey())
        );

        // updates
        layout_handler.getCurrent()->update();

        // display
        window->clear();
        layout_handler.getCurrent()->display();
        window->display();
    }

    return 0;
}
