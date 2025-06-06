#pragma once

#include "Layout.hpp"

using layout_map = std::map<std::string, Layout*>;

class LayoutHandler {
private:
    layout_map layouts_;
    std::string current_;
public:
    LayoutHandler() {};
    LayoutHandler(layout_map layouts): layouts_(layouts) {};
    virtual ~LayoutHandler();

    void add(std::string key, Layout* layout);
    Layout* get(std::string key);
    Layout* getCurrent();
    std::string getCurrentKey() const;
    void changeCurrent(std::string key);
};
