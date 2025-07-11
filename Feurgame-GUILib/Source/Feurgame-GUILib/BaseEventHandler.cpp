#include "BaseEventHandler.hpp"

#include <iostream>

std::string BaseEventHandler::get_current_layout() const {
    return current_layout_;
}

void BaseEventHandler::set_current_layout(const std::string& curr_layout) {
    current_layout_ = curr_layout;
}

void BaseEventHandler::handle(std::string& curr_layout) {
    current_layout_ = curr_layout;
    window_->handleEvents([this](const auto &event){ this->handle(event); });
    curr_layout = current_layout_;
}

void BaseEventHandler::handle(const sf::Event::Closed &event) {
    std::cout << "closing" << std::endl;
    this->window_->close();
}
