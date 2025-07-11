#include "Layout.hpp"

Layout::~Layout() {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        delete i->second;
}

base_event_handler_ptr Layout::getEventHandler() {
    if (!this->event_handler_)
        this->event_handler_ = std::make_shared<BaseEventHandler>(this->window_);

    return this->event_handler_;
}

void Layout::addWidget(std::string key, Widget* widget) {
    this->widgets_[key] = widget;
}

window_ptr Layout::getWindow() {
    return this->window_;
}

void Layout::display() const {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        if (i->second->canDisplay())
            i->second->draw(*this->window_, sf::RenderStates::Default);
}

void Layout::update() {
    for (auto i = this->widgets_.begin(); i != this->widgets_.end(); i++)
        i->second->update();
}

std::string Layout::handleEvents(std::string current_layout) {
    //this->getEventHandler()->handle(current_layout);
    if (!event_handler_) event_handler_ = getEventHandler();
    event_handler_->set_current_layout(current_layout);
    //auto& e = event_handler_;
    window_->handleEvents([this](const auto& event) { this->event_handler_->handle(event); });
    return event_handler_->get_current_layout();
}
