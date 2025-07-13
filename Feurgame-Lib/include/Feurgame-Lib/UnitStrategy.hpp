#pragma once

class UnitStrategy {
protected:
    float health_ = 100;
    unsigned int level_ = 1;
    float progress_ = 0;
    float morale_ = 100;
public:
    UnitStrategy() {};
    virtual ~UnitStrategy() = default;

    /**
     * Will be used to show the list of the possible attacks for the unit.
     * 
     * The signature will change.
     */
    virtual void get_possible_targets() const {};
    virtual void attack(UnitStrategy& enemy);
    /**
     * Will be used to update unit's state after moving on a different pos (if it's now surrounded the morale will fall etc...)
     */
    virtual void move() {}; // maybe signature will change
    virtual void heal();

    float get_health() const;
    void set_health(float health);
    void set_health_incr(float incr);
    void set_health_scalar(float scalar);

    unsigned int get_level() const;
    void add_progress(float progress);
    float get_morale() const;
    void set_morale(float morale);
    void set_morale_scalar(float scalar);
};

class InfanteryUnitStrategy : public UnitStrategy {};
class CavaleryUnitStrategy : public UnitStrategy {};
class ArtilleryUnitStrategy : public UnitStrategy {};
