#pragma once

#include <SFML/Graphics.hpp>

#include "Lib/Widget.hpp"

#include <string>

class PlayerNameTextBackgroundWidget : public ShapeWidget<sf::RectangleShape> {
public:
    PlayerNameTextBackgroundWidget(sf::Vector2f pos, sf::Vector2f size = {100, 40});
    ~PlayerNameTextBackgroundWidget() = default;

    void setPosition(sf::Vector2f pos) override;
};

class PlayerNameTextWidget : public TextWidget {
protected:
    sf::Vector2f internal_pos_;
public:
    PlayerNameTextWidget(sf::Vector2f pos) : TextWidget(
        std::make_unique<PlayerNameTextBackgroundWidget>(pos, sf::Vector2f{ 300, 40 }),
        "Hello, world!",
        {5, 5}
    ) {
        this->setStyles(); // TO FIX
    };
    ~PlayerNameTextWidget() = default;

    void setStyles() const override;
};
