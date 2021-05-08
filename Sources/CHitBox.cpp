#include "CHitBox.h"


// CONSTRUCTORS
CHitBox::CHitBox() :
    m_Position(0, 10),
    m_Scale(HITBOX_SCALE_DEFAULT, HITBOX_SCALE_DEFAULT){}

CHitBox::CHitBox(const SVector_2D& Pos, const SVector_2D& Scale):
    m_Position(Pos),
    m_Scale(Scale) {}


// SET/GET
SVector_2D CHitBox::GetPosition() const {
    return m_Position;
}

SVector_2D CHitBox::SetPosition(const SVector_2D& NewPos) {
    m_Position = NewPos;
}

SVector_2D CHitBox::GetScale() const {
    return m_Scale;
}

SVector_2D CHitBox::SetScale(const SVector_2D& NewScale) {
    m_Scale = NewScale;
}


// OVERRIDDEN
void CHitBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::RectangleShape PlayerHitBox(sf::Vector2f(m_Scale.X, m_Scale.Y));

    PlayerHitBox.setPosition(sf::Vector2f(m_Position.X, m_Position.Y));
    PlayerHitBox.setOutlineThickness(1.0f);
    PlayerHitBox.setOutlineColor(sf::Color::Red);
    PlayerHitBox.setFillColor(sf::Color::Transparent);

    target.draw(PlayerHitBox, states);
}
