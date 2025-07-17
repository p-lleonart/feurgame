#pragma once

#include <Feurgame-GUILib/Widget.hpp>

const int WINDOW_X = 640;
const int WINDOW_Y = 480;

class Movable {
protected:
    sf::Vector2f pos_;
public:
    void set_pos(const sf::Vector2f&);
    void set_x(float);
    void set_y(float);
    sf::Vector2f get_pos() const;
};

template<typename T>
class BarDisplay : public ContainerWidget {
protected:
    std::shared_ptr<T> rsc_;
public:
    /**
     * Note: hidden by default.
     */
    BarDisplay(std::shared_ptr<T> rsc)
        : rsc_(rsc), ContainerWidget({ WINDOW_X  / 2 - 200, WINDOW_Y - 120 }, {}) {
        toDisplay_ = false;

        sf::RectangleShape rectangle({ 400, 100 });
        rectangle.setPosition(pos_);
        rectangle.setFillColor(sf::Color(0, 255, 0));

        widgets_["background"] = new ShapeWidget<sf::RectangleShape>(rectangle);
    };
    virtual ~BarDisplay() = default;
};

template<typename T>
class DetailDisplay : public ContainerWidget {
protected:
    std::shared_ptr<T> rsc_;
public:
    /**
     * Note: hidden by default.
     */
    DetailDisplay(std::shared_ptr<T> rsc)
        : rsc_(rsc), ContainerWidget({ 10, WINDOW_Y - 210 }, {}) {
        toDisplay_ = false;

        sf::RectangleShape rectangle({ 150, 200 });
        rectangle.setPosition(pos_);
        rectangle.setFillColor(sf::Color(0, 0, 255));

        widgets_["background"] = new ShapeWidget<sf::RectangleShape>(rectangle);
    };
    virtual ~DetailDisplay() = default;
};
