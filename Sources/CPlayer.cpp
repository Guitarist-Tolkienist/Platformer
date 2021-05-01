#include "CPlayer.h"
#include "CGameView.h"

// Constructors
CPlayer::CPlayer() :
    CEntity() {
    // todo make standalone method
    m_Name = new char(strlen(PLAYER_NAME));
    std::strcpy(m_Name, PLAYER_NAME);
}

CPlayer::CPlayer(const CHitBox& HitBox) : CEntity(HitBox, PLAYER_SPRITE_FILE_NAME, MAX_PLAYER_HP) {
    m_Name = new char(strlen(PLAYER_NAME));
    std::strcpy(m_Name, PLAYER_NAME);
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
    CEntity::Tick(DeltaTime);

    UpdateText();
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

