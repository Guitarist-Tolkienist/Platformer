#include "CMapObject.h"
#include <iostream>

// CONSTRUCTORS
CMapObject::CMapObject(const CHitBox& HitBox, const char* SpriteFilename):
    m_HitBox(HitBox) {
        SetSprite(SpriteFilename);
}


void CMapObject::SetSprite(const char* TextureFilename) {
    if (!TextureFilename) return;

    // todo complete condition
    if (!m_Texture) {
    }

    m_Texture = new sf::Texture();
    if (!m_Texture->loadFromFile(TextureFilename)) {
        std::cout << "failed to load texture file" ;
    }

    m_Sprite = new sf::Sprite();
    m_Sprite->setTexture(*m_Texture);

    m_Sprite->setPosition(m_HitBox.GetPosition().X, m_HitBox.GetPosition().Y);

    float spriteWidth = m_HitBox.GetScale().X / (float)m_Texture->getSize().x;
    float spriteHeight = m_HitBox.GetScale().Y / (float)m_Texture->getSize().y;
    m_Sprite->scale(spriteWidth, spriteHeight);
}

void CMapObject::SetLocation(const SVector_2D& NewLocation) {
    // Set Location to HitBox & Sprite
    m_HitBox.SetPosition(NewLocation);
    m_Sprite->setPosition(NewLocation.X, NewLocation.Y);
}

void CMapObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_Sprite, states);
}
