#pragma once

#include <SFML/Graphics.hpp>
#include "Lib/Widget.hpp"

class ButtonWidget : public SpriteWidget {
public:
    ButtonWidget(std::string path, sf::IntRect area, bool sRgb) : SpriteWidget(path, area, sRgb) {};
    virtual ~ButtonWidget() = default;

    virtual bool button_clicked(sf::Vector2i mouse_pos) const;
};

class HomePlayButtonWidget : public ButtonWidget {
public:
    HomePlayButtonWidget() : ButtonWidget("assets/home_play_btn.png", {}, false) {
        this->pos_ = {50, 150};
        this->sprite_->setPosition(this->pos_);
        this->sprite_->scale({ 0.5, 0.5 });
    };
    ~HomePlayButtonWidget() = default;
};

class PlayerFormSubmitButtonWidget : public ButtonWidget {
public:
    PlayerFormSubmitButtonWidget() : ButtonWidget("assets/home_play_btn.png", {}, false) {
        this->pos_ = {350, 100};
        this->sprite_->setPosition(this->pos_);
        this->sprite_->scale({ 0.25, 0.25 });
    }
    ~PlayerFormSubmitButtonWidget() = default;
};
