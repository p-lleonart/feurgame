#pragma once

#include "string"

#include "Player.hpp"

class Nameable {
protected:
    std::string name_;
public:
    Nameable() {}
    Nameable(std::string name) : name_(name) {}

    std::string get_name() const;
    void set_string(std::string);
};

class Identifiable {
protected:
    unsigned int id_;
public:
    Identifiable() {}
    Identifiable(unsigned int id) : id_(id) {}

    unsigned int get_id() const;
};

class Entity : public Nameable, public Identifiable {
public:
    Entity() {}
    Entity(std::string name, unsigned int id) : Nameable(name), Identifiable(id) {}
};

class HasOwner {
protected:
    player_ptr owner_;
public:
    HasOwner() {}
    HasOwner(player_ptr owner) : owner_(owner) {}

    player_ptr get_owner();
};
