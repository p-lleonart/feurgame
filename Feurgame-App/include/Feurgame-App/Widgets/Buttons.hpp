#pragma once

#include <Feurgame-GUILib/Layout.hpp>

class ButtonWidget : public SpriteWidget {
protected:
    sf::Mouse::Button mouse_btn_ = sf::Mouse::Button::Left;
public:
    ButtonWidget(std::string path, sf::IntRect area, bool sRgb) : SpriteWidget(path, area, sRgb) {};
    virtual ~ButtonWidget() = default;

    virtual bool button_clicked(const sf::Event::MouseButtonPressed& event) const;
    
    virtual void callback(const sf::Event::MouseButtonPressed& event) {};
    virtual void callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout) {};
    virtual void callback(const sf::Event::MouseButtonPressed& event, std::string& current_layout) {std::cout << "btnwidget callback"<<std::endl;};
    virtual void callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout) {};

    virtual void process_callback(const sf::Event::MouseButtonPressed& event);
    virtual void process_callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout);
    virtual void process_callback(const sf::Event::MouseButtonPressed& event, std::string& current_layout);
    virtual void process_callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout);
};

class HomePlayButtonWidget : public ButtonWidget {
public:
    HomePlayButtonWidget() : ButtonWidget("assets/home_play_btn.png", {}, false) {
        this->pos_ = {50, 150};
        this->sprite_->setPosition(this->pos_);
        this->sprite_->scale({ 0.5, 0.5 });
    };
    ~HomePlayButtonWidget() = default;

    void callback(const sf::Event::MouseButtonPressed& event, std::string& current_layout) override {
        std::cout << "btn pressed" << std::endl;
        current_layout = "players_form";
    }
};
