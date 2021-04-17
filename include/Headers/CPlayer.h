#ifndef PLATFORMER_CPLAYER_H
#define PLATFORMER_CPLAYER_H

#include <iostream>
#include "CEntity.h"
#include <iostream>
#include <cstring>

const int MAX_PLAYER_NAME_SIZE = 15;
const int MAX_PLAYER_HP = 275;
const char PLAYER_SPRITE_FILE_NAME[] = "../Resources/knight.png";

class CPlayer: public CEntity {
    char* m_Name;

    bool m_bIsJumping;

    int m_StartFrame;
    const static int JUMP_FRAMES = 30;

public:
    CPlayer();
    CPlayer(const CHitBox&);
    CPlayer(const CHitBox&, const char*);
    ~CPlayer();

    void setName(char*);
    char* getName() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void Tick(float DeltaTime) override;
    void Jump();

    // OVERLOADED OPERATORS
public:
    CPlayer& operator=(const CPlayer*);
};


#endif //PLATFORMER_CPLAYER_H
