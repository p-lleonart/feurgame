#pragma once

#include <Feurgame-GUILib/Layout.hpp>
#include <Feurgame-GUILib/Widget.hpp>

const int WINDOW_X = 640;
const int WINDOW_Y = 480;
const int CLICKABLE_MARGIN = 30;

class Clickable {
protected:
    sf::Vector2f pos_;
public:
    Clickable() {}
    Clickable(sf::Vector2f pos) : pos_(pos) {}
    
    sf::Vector2f get_pos() const;
    bool is_clicked(const sf::Vector2f&) const;
};

class Movable : public Clickable {
public:
    void set_pos(const sf::Vector2f&);
    void set_x(float);
    void set_y(float);
};

class BaseDisplay : public ContainerWidget {
protected:
    window_ptr window_;
public:
    BaseDisplay(window_ptr window, sf::Vector2f pos) : window_(window), ContainerWidget(pos, {}) {
        toDisplay_ = false;
    };
    virtual ~BaseDisplay() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class BarDisplay : public BaseDisplay {
public:
    /**
     * Note: hidden by default.
     */
    BarDisplay(window_ptr window)
        : BaseDisplay(window, sf::Vector2f{ WINDOW_X  / 2 - 200, WINDOW_Y - 120 }) {
        sf::RectangleShape rectangle({ 400, 100 });
        rectangle.setPosition(pos_);
        rectangle.setFillColor(sf::Color(0, 255, 0));

        widgets_["background"] = new ShapeWidget<sf::RectangleShape>(rectangle);
    };
    virtual ~BarDisplay() = default;
};

class DetailDisplay : public BaseDisplay {
public:
    /**
     * Note: hidden by default.
     */
    DetailDisplay(window_ptr window)
        : BaseDisplay(window, sf::Vector2f{ 10, WINDOW_Y - 210 }) {
        sf::RectangleShape rectangle({ 150, 200 });
        rectangle.setPosition(pos_);
        rectangle.setFillColor(sf::Color(0, 0, 255));

        widgets_["background"] = new ShapeWidget<sf::RectangleShape>(rectangle);
    };
    virtual ~DetailDisplay() = default;
};
