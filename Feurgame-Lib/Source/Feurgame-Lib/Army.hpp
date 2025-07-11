#pragma once

#include "Player.hpp"
#include "UnitStrategy.hpp"

#include <string>
#include <vector>

class Unit {
private:
    unsigned int id_ = 0;
    std::string name_;
    std::string army_;
    player_ptr owner_;
    std::unique_ptr<UnitStrategy> strategy_;

public:
    Unit() {}
    Unit(
        std::unique_ptr<UnitStrategy> strategy,
        unsigned int id,
        std::string name,
        std::string army,
        player_ptr owner
    ) : strategy_(std::move(strategy)), id_(id), name_(name), army_(army), owner_(owner) {}
    Unit(const Unit& unit) :
        id_(unit.id_),
        name_(unit.name_),
        army_(unit.army_),
        owner_(unit.owner_),
        strategy_(std::make_unique<UnitStrategy>(*unit.strategy_)) {}

    static std::string create_unit_name(std::string unit_type, std::string army);

    unsigned int get_id() const;

    std::string get_name() const;
    void set_name(std::string name);
    
    std::string get_army() const;
    void set_army(std::string army);

    player_ptr get_owner();

    float get_health() const;
    void set_health(float health);
    void set_health_incr(float incr);
    void set_health_scalar(float scalar);

    unsigned int get_level() const;
    void add_progress(float progress);
    
    float get_morale() const;
    void set_morale(float morale);
    void set_morale_scalar(float scalar);

    UnitStrategy& get_strategy();

    void attack(Unit& enemy);
    void get_possible_targets() const;
    void move(); // maybe signature will change
    void heal();
};

using unit_ptr = std::shared_ptr<Unit>;
using unit_vector = std::vector<unit_ptr>;

class Army {
private:
    unsigned int id_ = 0;
    unit_vector units_;
    std::string name_;
    player_ptr owner_;
public:
    Army() {};
    Army(unsigned int id, std::string name, player_ptr owner) : id_(id), name_(name), owner_(owner) {};
    Army(unsigned int id, unit_vector units, std::string name, player_ptr owner)
        : id_(id), units_(units), name_(name), owner_(owner) {};

    unsigned int get_id() const;
    unit_vector get_units() const;
    unit_ptr get_unit(int i);
    std::string get_name() const;
    void set_name(std::string name);
    player_ptr get_owner();
};

using army_ptr = std::shared_ptr<Army>;
