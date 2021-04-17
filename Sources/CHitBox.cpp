#include "CHitBox.h"

// Constructor
CHitBox::CHitBox() :
    m_Position(0, 0),
    m_Scale(100, 100){}

CHitBox::CHitBox(const SVector_2D& Pos, const SVector_2D& Scale):
    m_Position(Pos),
    m_Scale(Scale) {}

SVector_2D CHitBox::GetPosition() const {
    return m_Position;
}

SVector_2D CHitBox::SetPosition(SVector_2D NewPos) {
    m_Position = NewPos;
}

SVector_2D CHitBox::GetScale() const {
    return m_Scale;
}

SVector_2D CHitBox::SetScale(SVector_2D NewScale) {
    m_Scale = NewScale;
}

void CHitBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    SVector_2D pos = GetPosition();
    SVector_2D scale = GetScale();

    sf::RectangleShape PlayerHitBox(sf::Vector2f(scale.m_X, scale.m_Y));
    PlayerHitBox.setPosition(sf::Vector2f(pos.m_X, pos.m_Y));
    PlayerHitBox.setOutlineThickness(1.0f);
    PlayerHitBox.setOutlineColor(sf::Color::Red);
    PlayerHitBox.setFillColor(sf::Color::Transparent);

    target.draw(PlayerHitBox, states);
}
