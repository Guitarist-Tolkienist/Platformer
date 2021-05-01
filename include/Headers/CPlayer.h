#ifndef PLATFORMER_CPLAYER_H
#define PLATFORMER_CPLAYER_H

#include <iostream>
#include "CEntity.h"
#include <iostream>
#include <cstring>

const int MAX_PLAYER_NAME_SIZE = 15;
const int MAX_PLAYER_HP = 275;
const char PLAYER_SPRITE_FILE_NAME[] = "../Resources/knight.png";
const char PLAYER_NAME[] = "Player";

class CPlayer: public CEntity {
    char* m_Name;

public:
    CPlayer();
    CPlayer(const CHitBox&);
    CPlayer(const CHitBox&, const char*);
    virtual ~CPlayer() override;

    void setName(char*);
    char* getName() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void Tick(float DeltaTime) override;

    // OVERLOADED OPERATORS
public:
    CPlayer& operator=(const CPlayer*);
};


#endif //PLATFORMER_CPLAYER_H
