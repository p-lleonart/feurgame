#pragma once

#include "Lib/Widget.hpp"

class PlayerNameTextWidget : public TextWidget {
public:
    PlayerNameTextWidget(sf::Vector2f pos) : TextWidget(
        std::make_unique<TextBackgroundWidget>(pos, sf::Vector2f{ 300, 40 }),
        "Hello, world!",
        {5, 5}
    ) {
        this->setStyles(); // TO FIX
    };
    ~PlayerNameTextWidget() = default;

    void setStyles() const override;
};
