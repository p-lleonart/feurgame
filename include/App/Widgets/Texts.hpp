#pragma once

#include "Lib/Widget.hpp"

class PlayerNameTextBackgroundWidget : public ShapeWidget<sf::RectangleShape> {
public:
    PlayerNameTextBackgroundWidget(sf::Vector2f pos, sf::Vector2f size = {100, 40});
    ~PlayerNameTextBackgroundWidget() = default;

    void setPosition(sf::Vector2f pos) override;
};

class PlayerNameTextWidget : public TextWidget {
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
