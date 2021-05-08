#include <sstream>
#include "CEntity.h"
#include "CGameView.h"

using sf::Keyboard;

// CONSTRUCTORS
CEntity::CEntity():
    sf::Drawable(),
    bIsHitBoxSelected(HITBOX_SELECTED_DEFAULT) {
        SetSprite(DEFAULT_ENTITY_SPRITE_FILE_NAME);

        m_Text = sf::Text("location: ", CAssets::GetInstance().m_Font, 20);
    }

CEntity::CEntity(const CHitBox& HitBox, const char* spriteFilename, float HP):
    sf::Drawable(),
    m_HitBox(HitBox),
    m_Health(HP),
    bIsHitBoxSelected(HITBOX_SELECTED_DEFAULT) {
        SetSprite(spriteFilename);

        m_Text = sf::Text("", CAssets::GetInstance().m_Font, 20);

        if (m_HitBox.GetPosition().Y + m_HitBox.GetScale().Y < EARTH_LOCATION) {
            EMovement.YMovement = AxisYMovement::Fall;
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

void CEntity::SetSprite(const char* TextureFilename) {
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

void CEntity::SetLocation(const SVector_2D& NewLocation) {
    // check if the character
    // goes beyond the window borders
    if (NewLocation.X < 0) {
        return;
    }
    if (NewLocation.X + m_HitBox.GetScale().X > WINDOW_WIDTH) {
        return;
    }

    // Set Location to HitBox & Sprite
    m_HitBox.SetPosition(NewLocation);
    m_Sprite->setPosition(NewLocation.X, NewLocation.Y);
}

SVector_2D CEntity::GetLocation() const{
    return m_HitBox.GetPosition();
}

SVector_2D CEntity::GetScale() const {
    return m_HitBox.GetScale();
}

const CHitBox* CEntity::GetHitBox() const {
    return &m_HitBox;
}

// UPDATE LOGIC
void CEntity::Tick(float DeltaTime) {
    MoveX(DeltaTime);
    MoveY(DeltaTime);

    HandleGravity();
}

void CEntity::UpdateText() {
    std::ostringstream buff1;
    buff1 << m_HitBox.GetPosition().X;
    std::string s1(buff1.str());

    std::ostringstream buff2;
    buff2 << m_HitBox.GetPosition().Y;
    std::string s2(buff2.str());

    std::ostringstream buff3;
    buff3 << m_FallVector.Y;
    std::string s3(buff3.str());


    std::string pos(s1 + ",  " + s2 + " | " + s3);
    m_Text.setString(pos.c_str());

    SVector_2D TextLocation = m_HitBox.GetPosition();
    TextLocation.Y -= 15;
    m_Text.setPosition(TextLocation.X, TextLocation.Y);
}

void CEntity::HandleGravity() {
    if (!m_RunningPlatform) return;

    if (GetHitBox()->GetPosition().X >= m_RunningPlatform->GetPosition().X + m_RunningPlatform->GetScale().X ||
        GetHitBox()->GetPosition().X + GetHitBox()->GetScale().X <= m_RunningPlatform->GetPosition().X) {
        ChangeYState(AxisYMovement::Fall);
    }

    if (EMovement.YMovement == AxisYMovement::Jump) {
        return;
    }

    float EntityFeetLocation_Y = m_HitBox.GetPosition().Y + m_HitBox.GetScale().Y;
    if (EntityFeetLocation_Y < m_RunningPlatform->GetPosition().Y) {
        ChangeYState(AxisYMovement::Fall);
    }
}


// MOVING ENTITY
void CEntity::Jump(float DeltaTime) {
    if (!IsJumping()) return;

    SVector_2D NewLoc = m_HitBox.GetPosition();
    NewLoc += m_JumpVector * DeltaTime;
    m_JumpVector += GRAVITY_VECTOR * DeltaTime;

    if (m_JumpVector.Y >= 0.0) {
        ChangeYState(AxisYMovement::Fall);
        return;
    }

    SetLocation(NewLoc);
}

void CEntity::Fall(float DeltaTime) {
    if (!IsFalling()) return;

    SVector_2D NewLoc = m_HitBox.GetPosition();
    NewLoc += m_FallVector * DeltaTime;
    m_FallVector += GRAVITY_VECTOR * DeltaTime;

    float EntityFeetLocation_Y = m_HitBox.GetPosition().Y + m_HitBox.GetScale().Y;
    if (EntityFeetLocation_Y < m_RunningPlatform->GetPosition().Y) {
        SetLocation(NewLoc);
    } else {
        ChangeYState(AxisYMovement::Static);
    }
}

void CEntity::MoveX(float DeltaTime) {
    switch (EMovement.XMovement) {
        case AxisXMovement::Left: {
            SVector_2D NewPos = GetLocation();

            if (EMovement.YMovement != AxisYMovement::Static) {
                NewPos -= (WALK_VECTOR * 0.7) * DeltaTime;
            } else {
                NewPos -= WALK_VECTOR * DeltaTime;
            }

            SetLocation(NewPos);
        } break;
        case AxisXMovement::Right: {
            SVector_2D NewPos = GetLocation();

            if (EMovement.YMovement != AxisYMovement::Static) {
                NewPos += (WALK_VECTOR * 0.7) * DeltaTime;
            } else {
                NewPos += WALK_VECTOR * DeltaTime;
            }


            SetLocation(NewPos);
        } break;
        default: break;
    }
}

void CEntity::MoveY(float DeltaTime) {
    switch (EMovement.YMovement) {
        case AxisYMovement::Jump:
            Jump(DeltaTime);
            break;
        case AxisYMovement::Fall:
            Fall(DeltaTime);
            break;
        default:
            break;
    }
}


// MOVING STATES
bool CEntity::IsFalling() const {
    return EMovement.YMovement == AxisYMovement::Fall;
}

bool CEntity::IsJumping() const {
    return EMovement.YMovement == AxisYMovement::Jump;
}

bool CEntity::IsRunning() const {
    return EMovement.XMovement != AxisXMovement::Static;
}

void CEntity::ChangeState(const EntityMovement& State) {
    EMovement = State;
}

void CEntity::ChangeXState(const AxisXMovement& State) {
    EMovement.XMovement = State;
}

void CEntity::ChangeYState(const AxisYMovement& State) {
    if (State == EMovement.YMovement) return;

    if (State == AxisYMovement::Jump && EMovement.YMovement == AxisYMovement::Fall) return;

    if (State == AxisYMovement::Jump) {
        m_JumpVector = JUMP_VECTOR;
    }

    if (State == AxisYMovement::Static) {
        m_JumpVector = ZeroVector_2D;
        m_FallVector = ZeroVector_2D;
    }

    EMovement.YMovement = State;
}

