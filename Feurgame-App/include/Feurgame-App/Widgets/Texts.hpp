#pragma once

#include <Feurgame-GUILib/Widget.hpp>

class PlayerNameTextWidget : public TextWidget {
public:
    PlayerNameTextWidget(sf::Vector2f pos, std::string name = "Hello, world!") : TextWidget(
        std::make_unique<TextBackgroundWidget>(pos, sf::Vector2f{ 300, 40 }),
        name,
        {5, 5}
    ) {
        this->setStyles(); // TO FIX
    };
    ~PlayerNameTextWidget() = default;

    void setStyles() const override;
};
