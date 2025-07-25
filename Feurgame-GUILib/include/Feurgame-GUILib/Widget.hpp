#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <string>

class Widget : public sf::Drawable {
protected:
    sf::Vector2f pos_;
    sf::Texture texture_;
    bool toDisplay_ = true;
public:
    Widget() {};
    virtual ~Widget() = default;

    virtual sf::Texture getTexture() const;

    void setToDisplay(bool d);
    bool canDisplay() const;

    sf::Vector2f getPosition() const;
    virtual void setPosition(sf::Vector2f pos) {};
    virtual sf::Vector2f getSize() const { return {0,0}; };
    virtual void setSize(sf::Vector2f pos) {};

    virtual void update() {};
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {};
};

class SpriteWidget : public Widget {
protected:
    std::unique_ptr<sf::Sprite> sprite_;
public:
    SpriteWidget(std::string path, sf::IntRect area, bool sRgb = false);
    virtual ~SpriteWidget() = default;

    sf::Sprite& getSprite() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void setPosition(sf::Vector2f pos) override;
    virtual sf::Vector2f getSize() const override;
};

template<typename T>
class ShapeWidget : public Widget {
protected:
    T shape_;
public:
    ShapeWidget() {};
    ShapeWidget(T shape) : shape_(shape) {}
    ShapeWidget(T shape, std::string path, sf::IntRect area = {}, bool sRgb = false) {
        if (!this->texture_.loadFromFile(path, sRgb, area)) {
            std::cerr << "ERROR: could instanciate " + path + " texture." << std::endl;
            exit(1);
        }

        shape.setTexture(&this->texture_);
        shape.setTextureRect(area);
        this->shape_ = shape;
    }
    virtual ~ShapeWidget() = default;

    T getShape() const {
        return this->shape_;
    };

    sf::Vector2f getSize() const override {
        return this->shape_.getSize();
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(this->shape_, states);
    }
};

class TextWidget : public Widget {
protected:
    /** default: {10, 10} */
    sf::Vector2f internal_pos_;

    sf::Font font_;
    std::unique_ptr<sf::Text> text_;
    int size_;
    std::unique_ptr<Widget> widget_;
public:
    TextWidget() {};
    TextWidget(
        std::unique_ptr<Widget> widget,
        std::string text,
        sf::Vector2f internal_pos = {10, 10},
        std::string font_path = "assets/fonts/MedievalSharp/MedievalSharp-Regular.ttf",
        int size = 24
    );
    virtual ~TextWidget() = default;

    virtual void setStyles() const {};
    static unsigned int calculateWidgetSize(const std::string& str, int charSize);

    void setWidget(std::unique_ptr<Widget> widget);
    void setText(std::string text);
    std::string getText() const;

    sf::Texture getTexture() const override;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void setPosition(sf::Vector2f pos) override;
    virtual sf::Vector2f getSize() const override;
};

class TextBackgroundWidget : public ShapeWidget<sf::RectangleShape> {
public:
    TextBackgroundWidget(sf::Vector2f pos, sf::Vector2f size = {100, 40});
    ~TextBackgroundWidget() = default;

    void setPosition(sf::Vector2f pos) override;

    static std::unique_ptr<TextBackgroundWidget> mk_unique(sf::Vector2f pos, sf::Vector2f size = {100, 40}) {
        return std::make_unique<TextBackgroundWidget>(pos, size);
    }
};

using widget_ptr = std::shared_ptr<Widget>;
using widget_vector = std::vector<Widget*>;
using widget_map = std::map<std::string, Widget*>;

class ListWidget : public Widget {
protected:
    widget_vector widgets_;

    /**
     * @param i the index of the item to adjust. By default, it adjusts all of them.
     */
    void adjustPositions(int i = -1);
public:
    /**
     * Note: the positions of the contained widgets are relative to the position of the ``ListWidget``.
     */
    ListWidget(sf::Vector2f pos, widget_vector widgets) : widgets_(widgets) {
        this->pos_ = pos;
        this->adjustPositions();
    }
    virtual ~ListWidget();

    void addWidget(Widget* widget);

    template<typename T>
    T* getWidget(int i) const {
        return dynamic_cast<T*>(this->widgets_[i]);
    }
    template<typename T>
    void setWidget(int i, T* new_val) {
        widgets_[i] = new_val;
    }
    unsigned int size() const;

    virtual void update() override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class ContainerWidget : public Widget {
protected:
    widget_map widgets_;

    /**
     * @param key the key of the item to adjust. By default, it adjusts all of them.
     */
    void adjustPositions(const std::string& key = "");
public:
    /**
     * Note: the positions of the contained widgets are relative to the position of the ``ContainerWidget``.
     */
    ContainerWidget(sf::Vector2f pos, widget_map widgets) : widgets_(widgets) {
        this->pos_ = pos;
        this->adjustPositions();
    }
    virtual ~ContainerWidget();

    void addWidget(const std::string& key, Widget* widget);

    template<typename T>
    T* getWidget(const std::string& key) {
        return dynamic_cast<T*>(this->widgets_[key]);
    }
    template<typename T>
    void setWidget(const std::string& key, T* new_val) {
        widgets_[key] = new_val;
    }

    virtual void update() override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
