#include "Lib/BaseEventHandler.hpp"

#include <iostream>

void BaseEventHandler::handle(std::string& current_layout) {
    this->current_layout = current_layout;
    this->window_->handleEvents([this](const auto &event){ this->handle(event); });
    current_layout = this->current_layout;
}

void BaseEventHandler::handle(const sf::Event::Closed &event) {
    std::cout << "closing" << std::endl;
    this->window_->close();
}
