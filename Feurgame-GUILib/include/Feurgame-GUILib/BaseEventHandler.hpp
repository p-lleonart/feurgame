#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

using window_ptr = std::shared_ptr<sf::RenderWindow>;

class BaseEventHandler {
protected:
    window_ptr window_;
    std::string current_layout;
public:
    BaseEventHandler(window_ptr window): window_(window) {};
    virtual ~BaseEventHandler() = default;
    
    void handle(std::string& current_layout);

    virtual void handle(const sf::Event::Closed& event);
    virtual void handle(const sf::Event::FocusGained& event) {};
    virtual void handle(const sf::Event::FocusLost& event) {};
    virtual void handle(const sf::Event::JoystickButtonPressed& event) {};
    virtual void handle(const sf::Event::JoystickButtonReleased& event) {};
    virtual void handle(const sf::Event::JoystickConnected& event) {};
    virtual void handle(const sf::Event::JoystickDisconnected& event) {};
    virtual void handle(const sf::Event::JoystickMoved& event) {};
    virtual void handle(const sf::Event::KeyPressed& event) {};
    virtual void handle(const sf::Event::KeyReleased& event) {};
    virtual void handle(const sf::Event::MouseButtonPressed& event) {};
    virtual void handle(const sf::Event::MouseButtonReleased& event) {};
    virtual void handle(const sf::Event::MouseEntered& event) {};
    virtual void handle(const sf::Event::MouseLeft& event) {};
    virtual void handle(const sf::Event::MouseMoved& event) {};
    virtual void handle(const sf::Event::MouseMovedRaw& event) {};
    virtual void handle(const sf::Event::MouseWheelScrolled& event) {};
    virtual void handle(const sf::Event::Resized& event) {};
    virtual void handle(const sf::Event::SensorChanged& event) {};
    virtual void handle(const sf::Event::TextEntered& event) {};
    virtual void handle(const sf::Event::TouchBegan& event) {};
    virtual void handle(const sf::Event::TouchEnded& event) {};
    virtual void handle(const sf::Event::TouchMoved& event) {};
};

using base_event_handler_ptr = std::shared_ptr<BaseEventHandler>;
