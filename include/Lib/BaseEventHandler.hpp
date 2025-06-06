#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

class BaseEventHandler {
protected:
    sf::RenderWindow* window_;
    std::string current_layout;
public:
    BaseEventHandler(sf::RenderWindow* window): window_(window) {};
    virtual ~BaseEventHandler() = default;
    
    void handle(std::string& current_layout);

    virtual void handle(const sf::Event::Closed &event);
    virtual void handle(const sf::Event::FocusGained &focus) {};
    virtual void handle(const sf::Event::FocusLost &focus) {};
    virtual void handle(const sf::Event::JoystickButtonPressed &button) {};
    virtual void handle(const sf::Event::JoystickButtonReleased &button) {};
    virtual void handle(const sf::Event::JoystickConnected &joystick) {};
    virtual void handle(const sf::Event::JoystickDisconnected &joystick) {};
    virtual void handle(const sf::Event::JoystickMoved &joystick) {};
    virtual void handle(const sf::Event::KeyPressed &event) {};
    virtual void handle(const sf::Event::KeyReleased &key) {};
    virtual void handle(const sf::Event::MouseButtonPressed &button) {};
    virtual void handle(const sf::Event::MouseButtonReleased &button) {};
    virtual void handle(const sf::Event::MouseEntered &mouse) {};
    virtual void handle(const sf::Event::MouseLeft &mouse) {};
    virtual void handle(const sf::Event::MouseMoved &mouse) {};
    virtual void handle(const sf::Event::MouseMovedRaw &mouse) {};
    virtual void handle(const sf::Event::MouseWheelScrolled $mouse) {};
    virtual void handle(const sf::Event::Resized &resized) {};
    virtual void handle(const sf::Event::SensorChanged &sensor) {};
    virtual void handle(const sf::Event::TextEntered &text) {};
    virtual void handle(const sf::Event::TouchBegan &touch) {};
    virtual void handle(const sf::Event::TouchEnded &touch) {};
    virtual void handle(const sf::Event::TouchMoved) {};
};
