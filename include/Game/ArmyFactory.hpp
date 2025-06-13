#pragma once

#include "Army.hpp"

// ArmyFactory and UnitFactory must handle at least, the ids
class UnitFactory {
private:
    static UnitFactory* instance_;
    unsigned int last_id_ = 1;
    
    UnitFactory() {};
public:
    UnitFactory(UnitFactory &unit_factory) = delete;
    void operator=(const UnitFactory&) = delete;
    ~UnitFactory() = default;

    static UnitFactory* get_instance();

    /**
     * @param name_is_type if true, the name will be considered as a unit type name (e.g "infantery") and
     * ``Unit::createUnitName()`` will be used to generate a name.
     */
    Unit create(std::unique_ptr<UnitStrategy> strategy, player_ptr owner, std::string army, std::string name, bool name_is_type = false);
};

class ArmyFactory {
private:
    static ArmyFactory* instance_;
    unsigned int last_id_ = 1;

    ArmyFactory() {};
public:
    ArmyFactory(ArmyFactory &army_factory) = delete;
    void operator=(const ArmyFactory&) = delete;
    ~ArmyFactory() = default;

    static ArmyFactory* get_instance();

    /**
     * units (opt)
     */
    Army create(unit_vector units, player_ptr owner, std::string name);
};
