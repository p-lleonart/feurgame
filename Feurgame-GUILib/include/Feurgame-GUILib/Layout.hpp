#pragma once

#include <map>

#include "BaseEventHandler.hpp"
#include "Widget.hpp"

using widget_map = std::map<std::string, Widget*>;

class Layout {
protected:
    virtual base_event_handler_ptr getEventHandler();

    template<typename T>
    static base_event_handler_ptr baseGetEventHandler(std::shared_ptr<Layout> layout) {
        if (!layout->event_handler_)
            layout->event_handler_ = std::make_shared<T>(layout);

        return layout->event_handler_;
    }

    base_event_handler_ptr event_handler_ = nullptr;
    widget_map widgets_;
    window_ptr window_;
public:
    Layout(window_ptr window) : window_(window) {};
    Layout(window_ptr window, widget_map widgets) : window_(window), widgets_(widgets) {};
    Layout(const Layout& layout) : window_(layout.window_), widgets_(layout.widgets_) {};
    virtual ~Layout();

    void addWidget(std::string key, Widget* widget);

    template<typename T>
    T* getWidget(std::string key) {
        return dynamic_cast<T*>(this->widgets_[key]);
    }
    template<typename T>
    void setWidget(std::string key, T* new_val) {
        widgets_[key] = new_val;
    }
    window_ptr getWindow();

    virtual void init() {};
    virtual void display() const;
    virtual void update();
    virtual std::string handleEvents(std::string current_layout);
};

using layout_ptr = std::shared_ptr<Layout>;

/**
 * This class will be used by events handler and will be the only child of ``BaseEventHandler``,
 * which will be the class used by layouts.
 */
class EventHandler : public BaseEventHandler {
protected:
    layout_ptr layout_;

    template<typename T>
    T* getWidget(std::string key) {
        return dynamic_cast<T*>(this->layout_->getWidget<T>(key));
    }
public:
    EventHandler(layout_ptr layout) : BaseEventHandler(layout->getWindow()), layout_(layout) {};
    virtual ~EventHandler() = default;
};
