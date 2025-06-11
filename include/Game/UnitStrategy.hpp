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

    float getHealth() const;
    void setHealth(float health);
    void setHealthIncr(float incr);
    void setHealthScalar(float scalar);

    unsigned int getLevel() const;
    void addProgress(float progress);
    float getMorale() const;
    void setMorale(float morale);
    void setMoraleScalar(float scalar);
};

class InfanteryUnitStrategy : public UnitStrategy {};
class CavaleryUnitStrategy : public UnitStrategy {};
class ArtilleryUnitStrategy : public UnitStrategy {};
