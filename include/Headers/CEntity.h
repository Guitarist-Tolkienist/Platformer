#ifndef PLATFORMER_CENTITY_H
#define PLATFORMER_CENTITY_H

#include <iostream>
#include "CHitBox.h"
#include "CUpdateable.h"

const char DEFAULT_ENTITY_SPRITE_FILE_NAME[] = "../Resources/knight.png";
const bool HITBOX_SELECTED_DEFAULT = true;


const _2D::SVector_2D WALK_VECTOR(500, 0.0f);
const _2D::SVector_2D JUMP_VECTOR(0, -500.0f);
const _2D::SVector_2D GRAVITY_VECTOR(0, 500.0f);

// todo remove from this file
const float EARTH_LOCATION = 550.0f;



enum class MovingState {
    Static, // When Entity is on earth todo rename
    Fall,
    Jump
};

enum class MovingDirection {
    Left,
    Right,
    None
};


enum class AxisXMovement {
    Left,
    Right,
    Static
};
enum class AxisYMovement {
    Jump,
    Fall,
    Static
};

struct EntityMovement {
    AxisXMovement XMovement = AxisXMovement::Static;
    AxisYMovement YMovement = AxisYMovement::Static;
};

class CEntity: public sf::Drawable, public IUpdatable {
protected:
    CHitBox m_HitBox;

    EntityMovement EMovement;

    float m_Health;

    SVector_2D m_WalkVector = ZeroVector_2D;
    SVector_2D m_JumpVector = ZeroVector_2D;
    SVector_2D m_FallVector = ZeroVector_2D;

    // APPEARANCE
    sf::Texture* m_Texture;
    sf::Sprite* m_Sprite;
public:
    CEntity();
    CEntity(const CHitBox& HitBox, const char* spriteFilename, float HP);
    virtual ~CEntity();

    SVector_2D GetLocation() const;
    SVector_2D GetScale() const;

protected:
    void SetLocation(const SVector_2D& NewLocation);
    void SetSprite(const char*);

private:
    void MoveX(float DeltaTime);
    void MoveY(float DeltaTime);

    void Fall(float DeltaTime);
    void Jump(float DeltaTime);

public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    void Tick(float DeltaTime) override;

    bool IsFalling() const;
    bool IsJumping() const;
    bool IsRunning() const;

    void ChangeState(const EntityMovement& State);
    void ChangeXState(const AxisXMovement& State);
    void ChangeYState(const AxisYMovement& State);

// DEBUG ONLY
protected:
    bool bIsHitBoxSelected;
    sf::Text m_Text;

public:
    void UpdateText();
};


#endif //PLATFORMER_CENTITY_H
