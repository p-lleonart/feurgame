#pragma once

#include <Feurgame-GUILib/Layout.hpp>

#include <Feurgame-Lib/Display.hpp>
#include <Feurgame-Lib/Game.hpp>

#include "Widgets/Buttons.hpp"
#include "Widgets/Texts.hpp"

class ChoosePlayerSubmitButtonWidget : public ButtonWidget {
public:
    ChoosePlayerSubmitButtonWidget() : ButtonWidget("assets/home_play_btn.png", {}, false) {
        this->pos_ = {350, 100};
        this->sprite_->setPosition(this->pos_);
        this->sprite_->scale({ 0.25, 0.25 });
    }
    ~ChoosePlayerSubmitButtonWidget() = default;
};

class ChoosePlayerLayout : public Layout {
protected:
    base_event_handler_ptr getEventHandler() override;
public:
    /**
     * Stores the names entered in PlayerForm layout.
     * 
     * TODO: find a better way to store them.
     */
    static std::vector<std::string> PLAYERS_NAMES;

    ChoosePlayerLayout(window_ptr window) : Layout(window) {}
    ~ChoosePlayerLayout() = default;
    
    void init() override {
        this->widgets_["title"] = new TextWidget(
            TextBackgroundWidget::mk_unique(sf::Vector2f{10, 10}, sf::Vector2f{ WINDOW_X - 2 * 10, 40 }),
            "choose which faction you are going to play"
        );

        widget_vector left_vect, right_vect;
        Game* game = Game::get_instance();

        for (int i = 0; i < ChoosePlayerLayout::PLAYERS_NAMES.size(); i++)
            left_vect.emplace_back(
                new PlayerNameTextWidget(
                    sf::Vector2f{0, (float) i * 50},
                    ChoosePlayerLayout::PLAYERS_NAMES[i]
                )
            );

        int bot_i = 1;
        for (int i = 0; i < game->get_map()->get_players().size(); i++) {
            if (game->get_map()->get_players()[i]->is_bot()) {
                left_vect.emplace_back(
                    new PlayerNameTextWidget(
                        sf::Vector2f{0, (float) i * 50},
                        std::string("bot #") + std::to_string(bot_i)
                    )
                );

                ChoosePlayerLayout::PLAYERS_NAMES.emplace_back(std::string("bot #") + std::to_string(bot_i));

                bot_i++;
            }
            
            right_vect.emplace_back(
                new PlayerNameTextWidget(
                    sf::Vector2f{10, (float) i * 50},
                    game->get_map()->get_players()[i]->get_name()
                        + (game->get_map()->get_players()[i]->is_bot() ? "(bot)" : "")
                )
            );
        }

        this->widgets_["left"] = new ListWidget(sf::Vector2f{10, 60}, left_vect);
        this->widgets_["right"] = new ListWidget(sf::Vector2f{WINDOW_X / 2, 60}, right_vect);
        this->widgets_["save"] = new ChoosePlayerSubmitButtonWidget();
        this->widgets_["save"]->setPosition({10, 310});
    }
};

class ChoosePlayerEventHandler : public EventHandler {
private:
    int focused_index_ = -1;
public:
    ChoosePlayerEventHandler(layout_ptr layout) : EventHandler(layout) {};

    void handle(const sf::Event::MouseButtonPressed& event) override;
};
