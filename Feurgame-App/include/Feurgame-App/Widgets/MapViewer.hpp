#pragma once

#include <Feurgame-GUILib/Widget.hpp>
#include <Feurgame-Lib/Display.hpp>
#include <Feurgame-Lib/Map.hpp>

class MapViewer : public ShapeWidget<sf::RectangleShape> {
private:
    const MapConfig config_;
public:
    MapViewer(const MapConfig& config) : config_(config) {
        if (!texture_.loadFromFile(config_.img)) {
            std::cerr << "ERROR: could instanciate " + config_.img + " map." << std::endl;
            exit(1);
        }
        
        shape_ = sf::RectangleShape({ (float) texture_.getSize().x, (float) texture_.getSize().y });
        shape_.setTexture(&texture_);
    }
    ~MapViewer() = default;
};
