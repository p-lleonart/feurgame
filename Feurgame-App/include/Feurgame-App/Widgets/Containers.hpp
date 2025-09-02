#pragma once

#include <Feurgame-GUILib/Widget.hpp>

#include <Feurgame-Lib/Army.hpp>
#include <Feurgame-Lib/City.hpp>
#include <Feurgame-Lib/Display.hpp>

class DisplayTextWidget : public TextWidget {
public:
    DisplayTextWidget(sf::Vector2f pos, std::string text = "") : TextWidget(
        TextBackgroundWidget::mk_unique(pos, sf::Vector2f{ 100, 20 }),
        text,
        {5, 5},
        "assets/fonts/MedievalSharp/MedievalSharp-Regular.ttf",
        18
    ) {};
    virtual ~DisplayTextWidget() = default;
};

class ArmyBarDisplay : public BarDisplay {
protected:
    army_ptr army_;
public:
    ArmyBarDisplay(window_ptr window, army_ptr army) : army_(army), BarDisplay(window) {
        widgets_["title"] = new DisplayTextWidget({}, army_->get_name() + " (" + army_->get_owner()->get_name() + ")");

        adjustPositions();
    };
    virtual ~ArmyBarDisplay() = default;
};

class CityBarDisplay : public BarDisplay {
protected:
    city_ptr city_;
public:
    CityBarDisplay(window_ptr window, city_ptr city) : city_(city), BarDisplay(window) {
        widgets_["title"] = new DisplayTextWidget({}, city_->get_name() + " (" + city_->get_owner()->get_name() + ")");

        adjustPositions();
    };
    virtual ~CityBarDisplay() = default;
};

// to do: buildings

class UnitDetailDisplay : public DetailDisplay {
protected:
    unit_ptr unit_;
public:
    UnitDetailDisplay(window_ptr window, unit_ptr unit) : unit_(unit), DetailDisplay(window) {
        widgets_["title"] = new DisplayTextWidget({}, unit_->get_name() + " (" + unit_->get_owner()->get_name() + ")");
    };
    virtual ~UnitDetailDisplay() = default;
};
