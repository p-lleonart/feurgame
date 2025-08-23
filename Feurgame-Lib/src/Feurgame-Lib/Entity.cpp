#include <Feurgame-Lib/Entity.hpp>

std::string Nameable::get_name() const {
    return name_;
}

void Nameable::set_string(std::string name) {
    name_ = name;
}

unsigned int Identifiable::get_id() const {
    return id_;
}

player_ptr HasOwner::get_owner() {
    return owner_;
}
