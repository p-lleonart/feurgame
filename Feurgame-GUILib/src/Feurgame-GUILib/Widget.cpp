#include <Feurgame-GUILib/Widget.hpp>

sf::Texture Widget::getTexture() const {
    return this->texture_;
}

void Widget::setToDisplay(bool d) {
    this->toDisplay_ = d;
}

bool Widget::canDisplay() const {
    return this->toDisplay_;
}

sf::Vector2f Widget::getPosition() const {
    return this->pos_;
}

SpriteWidget::SpriteWidget(std::string path, sf::IntRect area, bool sRgb) {
    if (!this->texture_.loadFromFile(path, sRgb, area)) {
        std::cerr << "ERROR: could instanciate " + path + " texture." << std::endl;
        exit(1);
    }

    this->sprite_ = std::make_unique<sf::Sprite>(this->texture_);
}

sf::Sprite& SpriteWidget::getSprite() const {
    return *this->sprite_;
}

void SpriteWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*this->sprite_, states);
}

void SpriteWidget::setPosition(sf::Vector2f pos) {
    this->sprite_->setPosition(pos);
    this->pos_ = pos;
}

sf::Vector2f SpriteWidget::getSize() const {
    return this->sprite_->getGlobalBounds().size;
}

TextWidget::TextWidget(std::unique_ptr<Widget> widget, std::string text, sf::Vector2f internal_pos, std::string font_path, int size) {
    if (!this->font_.openFromFile(font_path)) {
        std::cerr << "ERROR: could instanciate " + font_path + " font." << std::endl;
        exit(1);
    }

    this->text_ = std::make_unique<sf::Text>(this->font_);
    this->text_->setString(text);
    this->text_->setCharacterSize(size);

    this->setStyles();
    this->internal_pos_ = internal_pos;
    this->widget_ = std::move(widget);
    this->pos_ = this->widget_->getPosition();

    this->text_->setPosition({
        this->widget_->getPosition().x + this->internal_pos_.x,
        this->widget_->getPosition().y + this->internal_pos_.y,
    });
}

unsigned int TextWidget::calculateWidgetSize(const std::string& str, int charSize) {
    return str.length() * charSize;
}

void TextWidget::setText(std::string text) {
    this->text_->setString(text);
}

std::string TextWidget::getText() const {
    return this->text_->getString();
}

void TextWidget::setWidget(std::unique_ptr<Widget> widget) {
    this->widget_ = std::move(widget);
}

sf::Texture TextWidget::getTexture() const {
    return this->font_.getTexture(this->size_);
}

void TextWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    this->widget_->draw(target, states);
    target.draw(*this->text_, states);
}

void TextWidget::setPosition(sf::Vector2f pos) {
    this->widget_->setPosition(pos);
    this->text_->setPosition(pos);
    this->pos_ = pos;
}

sf::Vector2f TextWidget::getSize() const {
    return this->widget_->getSize();
}

TextBackgroundWidget::TextBackgroundWidget(sf::Vector2f pos, sf::Vector2f size) {
    this->pos_ = pos;
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(pos);
    rectangle.setFillColor(sf::Color(255, 0, 0));

    this->shape_ = rectangle;
}

void TextBackgroundWidget::setPosition(sf::Vector2f pos) {
    this->shape_.setPosition(pos);
    this->pos_ = pos;
}

void ListWidget::adjustPositions(int i) {
    sf::Vector2f w_pos;
    
    if (i == -1) {
        for (int i = 0; i < this->widgets_.size(); i++) {
            w_pos = this->widgets_[i]->getPosition();
            this->widgets_[i]->setPosition({ this->pos_.x + w_pos.x, this->pos_.y + w_pos.y });
        }
        return;
    }
    
    w_pos = this->widgets_[i]->getPosition();
    this->widgets_[i]->setPosition({ this->pos_.x + w_pos.x, this->pos_.y + w_pos.y });
}

ListWidget::~ListWidget() {
    for (int i = 0; i < this->widgets_.size(); i++)
        delete this->widgets_[i];
}

void ListWidget::addWidget(Widget* widget) {
    this->widgets_.push_back(widget);
    this->adjustPositions(this->widgets_.size() - 1);
}

unsigned int ListWidget::size() const {
    return this->widgets_.size();
}

void ListWidget::update() {
    for (int i = 0; i < this->widgets_.size(); i++)
        this->widgets_[i]->update();
}

void ListWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < this->widgets_.size(); i++)
        if (this->widgets_[i]->canDisplay())
            this->widgets_[i]->draw(target, states);
}
