#include "CHitBox.h"


// CONSTRUCTORS
CHitBox::CHitBox() :
    m_Position(0, 0),
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

    sf::RectangleShape PlayerHitBox(sf::Vector2f(m_Scale.m_X, m_Scale.m_Y));

    PlayerHitBox.setPosition(sf::Vector2f(m_Position.m_X, m_Position.m_Y));
    PlayerHitBox.setOutlineThickness(1.0f);
    PlayerHitBox.setOutlineColor(sf::Color::Red);
    PlayerHitBox.setFillColor(sf::Color::Transparent);

    target.draw(PlayerHitBox, states);
}
