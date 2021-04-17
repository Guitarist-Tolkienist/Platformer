#include "CPlayer.h"
#include "CGameView.h"

// Constructors
CPlayer::CPlayer() :
    CEntity() {
    // todo make standalone method
    m_Name = new char(strlen("Player"));
    std::strcpy(m_Name, "Player");
}

CPlayer::CPlayer(const CHitBox& HitBox) : CEntity(HitBox, PLAYER_SPRITE_FILE_NAME, MAX_PLAYER_HP) {
    m_Name = new char(strlen("Player"));
    std::strcpy(m_Name, "Player");
}
CPlayer::CPlayer(const CHitBox& HitBox, const char* SpriteFilename) : CEntity(HitBox, SpriteFilename, MAX_PLAYER_HP) {
    m_Name = new char(strlen("Player"));
    std::strcpy(m_Name, "Player");
}

CPlayer::~CPlayer() {
    if (m_Name) {
        delete m_Name;
        m_Name = nullptr;
    }
}

void CPlayer::setName(char* newName) {
    if(m_Name) {
        delete m_Name;
        m_Name = nullptr;
    }

    m_Name = new char(strlen(newName));
    strcpy(m_Name, newName);
}

char* CPlayer::getName() const {
    return m_Name;
}

void CPlayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (bIsHitBoxSelected) {
        m_HitBox.draw(target, states);
    }

    target.draw(*m_Sprite, states);
    target.draw(m_Text);
}

void CPlayer::Tick(float DeltaTime) {
    if(m_bIsJumping) {
        m_StartFrame++;

        SVector_2D NewLoc = m_HitBox.GetPosition();
        NewLoc.m_Y -= JUMP_STEP * DeltaTime;

        SetLocation(NewLoc);

        if (m_StartFrame > JUMP_FRAMES) {
            m_bIsJumping = false;

            m_bIsFalling = true;
        }

    } else {
        if (m_HitBox.GetPosition().m_Y + m_HitBox.GetScale().m_Y < EARTH_LOCATION && m_bIsFalling) {
            SVector_2D NewLoc = m_HitBox.GetPosition();
            NewLoc.m_Y += GRAVITY_STEP * DeltaTime;

            SetLocation(NewLoc);
        } else if (m_HitBox.GetPosition().m_Y + m_HitBox.GetScale().m_Y >= EARTH_LOCATION) {
            SVector_2D NewLoc = m_HitBox.GetPosition();
            NewLoc.m_Y = EARTH_LOCATION - m_HitBox.GetScale().m_Y;

            SetLocation(NewLoc);

            m_bIsFalling = false;
        }
    }

    if (m_bMoving) {
        try {
            SVector_2D NewPos = GetLocation();

            if (m_MovingState == MovingState::Left) {
                NewPos.m_X -= m_MovingStep;
            }
            if (m_MovingState == MovingState::Right) {
                NewPos.m_X += m_MovingStep;
            }

            // check if the character
            // goes beyond the window borders
            if (NewPos.m_X < 0) {
                throw 5;
            }
            if (NewPos.m_X + m_HitBox.GetScale().m_X > WINDOW_WIDTH) {
                throw 6;
            }

            m_HitBox.SetPosition(NewPos);
            m_Sprite->setPosition(m_HitBox.GetPosition().m_X,
                                  m_HitBox.GetPosition().m_Y);
        } catch (int ex) {
            if (ex == 5) {
//            std::cout << "moving forbidden - too left\n";
            }
            if (ex == 6) {
//            std::cout << "moving forbidden - too right\n";
            }
        }

        UpdateText();
    }

    UpdateText();
}

void CPlayer::Jump() {
    if (!m_bIsJumping && !m_bIsFalling) {
        m_bIsJumping = true;
        m_StartFrame = 0;

        m_bIsFalling = false;
    }
}

// OVERLOADED OPERATORS

CPlayer& CPlayer::operator=(const CPlayer* Player) {
    // todo implement assignment operator
    m_HitBox = Player->m_HitBox;
    m_Sprite = Player->m_Sprite;
    m_Texture = Player->m_Texture;
    m_Health = Player->m_Health;

    return *this;
}

