#include <Feurgame-GUILib/Layout.hpp>

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
    auto it = widgets_.find(key);

    if (it == widgets_.end())
        widgets_.insert({key, widget});
    else
        widgets_.at(key) = widget;
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
    this->getEventHandler()->handle(current_layout);
    return current_layout;
}
