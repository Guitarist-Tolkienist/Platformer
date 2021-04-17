#ifndef PLATFORMER_CENTITY_H
#define PLATFORMER_CENTITY_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "CHitBox.h"
#include "CUpdateable.h"

const char DEFAULT_ENTITY_SPRITE_FILE_NAME[] = "../Resources/knight.png";
const bool HITBOX_SELECTED_DEFAULT = true;
const float MOVING_STEP_DEFAULT = 5.5;

// todo remove from this file
const int EARTH_LOCATION = 450;
const float GRAVITY_STEP = 1.5f;
const float JUMP_STEP = 1.5f;

enum MovingState {
    Left,
    Right,
    None
};

class CEntity: public sf::Drawable, public IUpdatable {
protected:
    MovingState m_MovingState;
    bool m_bMoving;
    bool m_bIsFalling;

    float m_Health;
    float m_MovingStep;

    sf::Texture* m_Texture;
    sf::Sprite* m_Sprite;
    CHitBox m_HitBox;
public:
    CEntity();
    CEntity(const CHitBox& HitBox, const char* spriteFilename, float HP);
    ~CEntity();

    void Move(const MovingState);
    void SetLocation(SVector_2D NewLocation);
    SVector_2D GetLocation() const;
    SVector_2D GetScale() const;

protected:
    void SetSprite(const char*);
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void Tick(float DeltaTime) = 0;

    // DEBUG ONLY
protected:
    bool bIsHitBoxSelected;
    sf::Text m_Text;

public:
    void UpdateText();
};


#endif //PLATFORMER_CENTITY_H
