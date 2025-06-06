#include "Lib/Layout.hpp"

Layout::~Layout() {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        delete i->second;
    delete this->event_handler_;
}

BaseEventHandler* Layout::getEventHandler() {
    if (!this->event_handler_)
        this->event_handler_ = new BaseEventHandler(this->window_);

    return this->event_handler_;
}

void Layout::addWidget(std::string key, Widget widget) {
    this->widgets_[key] = new Widget(widget);
}

sf::RenderWindow& Layout::getWindow() {
    return this->window_;
}

void Layout::display() const {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        if (i->second->canDisplay())
            i->second->draw(this->window_, sf::RenderStates::Default);
}

void Layout::update() {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        i->second->update();
}

std::string Layout::handleEvents(std::string current_layout) {
    this->getEventHandler()->handle(current_layout);
    return current_layout;
}
