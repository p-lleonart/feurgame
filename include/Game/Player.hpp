#pragma once

#include <SFML/Graphics.hpp>
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

    void copy(Player& player) const;

    std::string getName() const;
    sf::Color getColor() const;
    bool isAlive() const;
    void kill();
};

static Player DEFAULT_PLAYER = Player("unknown", {0,0,0});
