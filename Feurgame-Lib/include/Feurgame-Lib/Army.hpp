#pragma once

#include "Display.hpp"
#include "Entity.hpp"
#include "UnitStrategy.hpp"

#include <string>
#include <vector>

/**
 * Note: ``Movable::pos_`` initialization isn't required inside of the ``Unit`` constructor because
 * it is only needed in Battle mode and the player will choose were the unit will be.
 * 
 * This isn't the same for ``Army``, because the army position is required in game context.
 */
class Unit : public Entity, public HasOwner, public Movable {
private:
    std::string army_;
    std::unique_ptr<UnitStrategy> strategy_;

public:
    Unit() {}
    Unit(
        std::unique_ptr<UnitStrategy> strategy,
        unsigned int id,
        std::string name,
        std::string army,
        player_ptr owner
    ) : strategy_(std::move(strategy)), Entity(name, id), HasOwner(owner), army_(army) {}
    Unit(const Unit& unit) :
        Entity(unit.name_, unit.id_),
        HasOwner(unit.owner_),
        army_(unit.army_),
        strategy_(std::make_unique<UnitStrategy>(*unit.strategy_)) {}

    static std::string create_unit_name(std::string unit_type, std::string army);
    
    std::string get_army() const;
    void set_army(std::string army);

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

class Army : public Entity, public HasOwner, public Movable {
private:
    unit_vector units_;
public:
    Army() {};
    Army(unsigned int id, sf::Vector2f pos, std::string name, player_ptr owner)
        : Entity(name, id), HasOwner(owner) {
        pos_ = pos;
    };
    Army(unsigned int id, sf::Vector2f pos, unit_vector units, std::string name, player_ptr owner)
        : Entity(name, id), HasOwner(owner), units_(units) {
        pos_ = pos;
    };

    unit_vector get_units() const;
    unit_ptr get_unit(int i);
};

using army_ptr = std::shared_ptr<Army>;
