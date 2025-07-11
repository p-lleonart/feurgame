#include "LayoutHandler.hpp"

LayoutHandler::~LayoutHandler() {
    for (auto i = this->layouts_.begin(); i != this->layouts_.end(); i++)
        delete i->second;
}

void LayoutHandler::add(std::string key, Layout* layout) {
    this->layouts_[key] = layout;
}

Layout* LayoutHandler::get(std::string key) {
    return this->layouts_[key];
}

Layout* LayoutHandler::getCurrent() {
    return this->get(this->current_);
}

std::string LayoutHandler::getCurrentKey() const {
    return this->current_;
}

void LayoutHandler::changeCurrent(std::string key) {
    this->current_ = key;
}
