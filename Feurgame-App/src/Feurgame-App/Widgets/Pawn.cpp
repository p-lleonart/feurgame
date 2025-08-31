#include <Feurgame-App/Widgets/Pawn.hpp>

PawnWidget::PawnWidget(std::string icon_path, sf::Vector2f pos) : ButtonWidget(icon_path, {}, false) {
    pos_ = pos;
    
    sprite_->scale({0.25, 0.25});
    sprite_->setPosition(pos_);
}

void CityPawnWidget::callback(const sf::Event::MouseButtonPressed& event) {
    std::cout << city_->get_name() << " " << city_->get_owner()->get_name() << std::endl;
}

void ArmyPawnWidget::callback(const sf::Event::MouseButtonPressed& event) {
    std::cout << army_->get_name() << " " << army_->get_owner()->get_name() << std::endl;
}
