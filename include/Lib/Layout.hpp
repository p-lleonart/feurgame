#pragma once

#include <map>
#include <string>

#include "BaseEventHandler.hpp"
#include "Widget.hpp"

using widget_map = std::map<std::string, Widget*>;

class Layout {
protected:
    virtual BaseEventHandler* getEventHandler();

    BaseEventHandler* event_handler_ = nullptr;
    widget_map widgets_;
    sf::RenderWindow* window_;
public:
    Layout() {};
    Layout(sf::RenderWindow* window) : window_(window) {};
    Layout(sf::RenderWindow* window, widget_map widgets) : window_(window), widgets_(widgets) {};
    Layout(const Layout& layout) : window_(layout.window_), widgets_(layout.widgets_) {};
    virtual ~Layout();

    void addWidget(std::string key, Widget widget);

    template<typename T>
    T* getWidget(std::string key) {
        return dynamic_cast<T*>(this->widgets_[key]);
    }
    sf::RenderWindow* getWindow();

    virtual void display() const;
    virtual void update();
    virtual std::string handleEvents(std::string current_layout);
};

/**
 * this class will be used by events handler and will be the only child of base event handler,
 * which will be the class used by layouts
 */
class EventHandler : public BaseEventHandler {
protected:
    Layout& layout_;
public:
    EventHandler(Layout& layout) : BaseEventHandler(layout.getWindow()), layout_(layout) {};
    virtual ~EventHandler() = default;
};
