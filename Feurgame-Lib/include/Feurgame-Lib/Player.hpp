#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

class Player {
private:
    std::string name_;
    sf::Color color_;
    bool is_alive_ = false;
public:
    Player() {}
    Player(std::string name, sf::Color color) : name_(name), color_(color) {};
    ~Player() = default;

    std::string get_name() const;
    sf::Color get_color() const;
    bool is_alive() const;
    void kill();
};

using player_ptr = std::shared_ptr<Player>;
