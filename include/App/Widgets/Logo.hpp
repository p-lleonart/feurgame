#pragma once

#include <SFML/Graphics.hpp>
#include "Lib/Widget.hpp"

class LogoWidget : public SpriteWidget {
public:
    LogoWidget() : SpriteWidget("assets/logo.png", {}, false) {
        sf::Vector2f size = this->sprite_->getGlobalBounds().size;
        this->pos_ = { ((float) 640 - size.x) / 2, 25};

        this->sprite_->scale({ 0.5, 0.5 });
        this->sprite_->setPosition(this->pos_);
    };
    ~LogoWidget() = default;
};