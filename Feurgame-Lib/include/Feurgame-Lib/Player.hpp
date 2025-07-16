#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

class Player {
private:
    std::string name_;
    sf::Color color_;
    bool is_alive_ = false;
    bool is_bot_ = false;
public:
    Player() {}
    Player(std::string name, sf::Color color, bool is_bot = false)
        : name_(name), color_(color), is_bot_(is_bot) {};
    ~Player() = default;

    void set_name(const std::string&);
    std::string get_name() const;
    sf::Color get_color() const;
    bool is_alive() const;
    bool is_bot() const;
    void kill();
};

using player_ptr = std::shared_ptr<Player>;
