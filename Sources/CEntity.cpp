#include <sstream>
#include "CEntity.h"
#include "CGameView.h"
using sf::Keyboard;

// Constructors
CEntity::CEntity():
    sf::Drawable(),
    bIsHitBoxSelected(HITBOX_SELECTED_DEFAULT),
    m_MovingStep(MOVING_STEP_DEFAULT) {
        SetSprite(DEFAULT_ENTITY_SPRITE_FILE_NAME);

        m_Text = sf::Text("location: ", CAssets::GetInstance().m_Font, 20);
    }

CEntity::CEntity(const CHitBox& HitBox, const char* spriteFilename, float HP):
    sf::Drawable(),
    m_HitBox(HitBox),
    m_Health(HP),
    bIsHitBoxSelected(HITBOX_SELECTED_DEFAULT),
    m_MovingStep(MOVING_STEP_DEFAULT) {
        SetSprite(spriteFilename);

        m_Text = sf::Text("", CAssets::GetInstance().m_Font, 20);

        if (m_HitBox.GetPosition().m_Y + m_HitBox.GetScale().m_Y < EARTH_LOCATION) {
            m_bIsFalling = true;
        }
    }

CEntity::~CEntity() {
    if (m_Texture) {
        delete m_Texture;
        m_Texture = nullptr;
    }

    if (m_Sprite) {
        delete m_Sprite;
        m_Sprite = nullptr;
    }
}


void CEntity::Move(MovingState key) {
    switch (key) {
        case MovingState::Left:
        case MovingState::Right:
            m_bMoving = true;
            break;
        case MovingState::None:
            m_bMoving = false;
            break;
        default: break;
    }

    m_MovingState = key;
}

void CEntity::SetSprite(const char* textureFilename) {
    // todo complete condition
    if (!m_Texture) {
    }

    m_Texture = new sf::Texture();
    if (!m_Texture->loadFromFile(textureFilename)) {
        std::cout << "failed to load texture file" ;
    }

    m_Sprite = new sf::Sprite();
    m_Sprite->setTexture(*m_Texture);

    m_Sprite->setPosition(m_HitBox.GetPosition().m_X, m_HitBox.GetPosition().m_Y);

    float spriteWidth = m_HitBox.GetScale().m_X/(float)m_Texture->getSize().x;
    float spriteHeight = m_HitBox.GetScale().m_Y/(float)m_Texture->getSize().y;
    m_Sprite->scale(spriteWidth, spriteHeight);
}

void CEntity::SetLocation(SVector_2D NewLocation) {
    m_HitBox.SetPosition(NewLocation);
    m_Sprite->setPosition(NewLocation.m_X, NewLocation.m_Y);
}

SVector_2D CEntity::GetLocation() const{
    return m_HitBox.GetPosition();
}

void CEntity::UpdateText() {
    std::ostringstream buff1;
    buff1 << m_HitBox.GetPosition().m_X;
    std::string s1(buff1.str());
    std::ostringstream buff2;
    buff2 << m_HitBox.GetPosition().m_Y;
    std::string s2(buff2.str());

    std::string pos(s1 + ",  " + s2);
    m_Text.setString(pos.c_str());

    SVector_2D TextLocation = m_HitBox.GetPosition();
    TextLocation.m_Y -= 15;
    m_Text.setPosition(TextLocation.m_X, TextLocation.m_Y);
}

SVector_2D CEntity::GetScale() const {
    return m_HitBox.GetScale();
}
/*
void CEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    SDot pos = m_HitBox.GetPosition();
    SDot scale = m_HitBox.GetScale();

    if (bIsHitBoxSelected) {
        sf::RectangleShape PlayerHitBox(sf::Vector2f(scale.m_X, scale.m_Y));
        PlayerHitBox.setPosition(sf::Vector2f(pos.m_X, pos.m_Y));
        PlayerHitBox.setOutlineThickness(1.0f);
        PlayerHitBox.setOutlineColor(sf::Color::Red);
        PlayerHitBox.setFillColor(sf::Color::Transparent);

        target.draw(PlayerHitBox, states);
    }
    target.draw(*m_Sprite, states);
}*/
