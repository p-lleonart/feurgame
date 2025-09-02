#include <Feurgame-App/Widgets/Pawn.hpp>

PawnWidget::PawnWidget(std::string icon_path, sf::Vector2f pos) : ButtonWidget(icon_path, {}, false) {
    pos_ = pos;
    
    sprite_->scale({0.25, 0.25});
    sprite_->setPosition(pos_);
}

void CityPawnWidget::callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout) {
    std::cout << city_->get_name() << " " << city_->get_owner()->get_name() << std::endl;
    auto city_bar = new CityBarDisplay(layout->getWindow(), city_);
    city_bar->setToDisplay(true);
    layout->addWidget("bar", city_bar);
}

void ArmyPawnWidget::callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout) {
    std::cout << army_->get_name() << " " << army_->get_owner()->get_name() << std::endl;
    auto army_bar = new ArmyBarDisplay(layout->getWindow(), army_);
    army_bar->setToDisplay(true);
    layout->addWidget("bar", army_bar);
}
