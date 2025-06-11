#pragma once

#include "Player.hpp"
#include "UnitStrategy.hpp"

#include <string>
#include <vector>

class Unit {
private:
    unsigned int id_;
    std::string name_;
    std::string army_;
    Player& owner_;
    std::unique_ptr<UnitStrategy> strategy_;

public:
    Unit(Player& player = DEFAULT_PLAYER) : id_(0), owner_(player) {}
    Unit(
        std::unique_ptr<UnitStrategy> strategy,
        unsigned int id,
        std::string name,
        std::string army,
        Player& owner
    ) : strategy_(std::move(strategy)), id_(id), army_(army), owner_(owner) {}
    Unit(const Unit& unit) :
        id_(unit.id_),
        name_(unit.name_),
        army_(unit.army_),
        owner_(unit.owner_),
        strategy_(std::make_unique<UnitStrategy>(*unit.strategy_)) {}

    static std::string createUnitName(std::string type, std::string army);

    void copy(Unit& unit) const;

    unsigned int getId() const;

    std::string getName() const;
    void setName(std::string name);
    
    std::string getArmy() const;
    void setArmy(std::string army);

    Player& getOwner() const;

    float getHealth() const;
    void setHealth(float health);
    void setHealthIncr(float incr);
    void setHealthScalar(float scalar);

    unsigned int getLevel() const;
    void addProgress(float progress);
    
    float getMorale() const;
    void setMorale(float morale);
    void setMoraleScalar(float scalar);

    UnitStrategy& getStrategy();

    void attack(Unit& enemy);
    void get_possible_targets() const;
    void move(); // maybe signature will change
    void heal();
};

using unit_vector = std::vector<Unit>;

class Army {
private:
    unsigned int id_;
    unit_vector units_;
    std::string name_;
    Player& owner_;
public:
    Army(Player& player = DEFAULT_PLAYER) : owner_(player) {}
    Army(unsigned int id, std::string name, Player& owner) : id_(id), name_(name), owner_(owner) {};
    Army(unsigned int id, unit_vector units, std::string name, Player& owner)
        : id_(id), units_(units), name_(name), owner_(owner) {};
    
    void copy(Army& army) const;

    unsigned int getId() const;
    unit_vector getUnits() const;
    Unit& getUnit(int i);
    std::string getName() const;
    void setName(std::string name);
    Player& getOwner() const;
};

static Army DEFAULT_ARMY = Army();
