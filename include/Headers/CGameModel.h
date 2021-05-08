#ifndef PLATFORMER_CGAMEMODEL_H
#define PLATFORMER_CGAMEMODEL_H

#include <chrono>
#include <algorithm>
#include <array>
#include "CPlayer.h"
#include "CMapObject.h"

// Forward declaration
class CGameView;
class CGameController;

const float LEVEL_WIDTH = 2000.f;
const float LEVEL_HEIGHT = 650.f;

const float WINDOW_WIDTH = 1300.f;
const float WINDOW_HEIGHT = 650.f;

class CGameModel: public IUpdatable{
    int players_quantity;

    CPlayer* m_Player;

    CHitBox* m_EarthPlatform;

    static const int NPC_QUANTITY = 2;
    std::array<CPlayer, NPC_QUANTITY> m_NPC;
    std::array<CMapObject, 0> m_Objects;
public:
    CGameModel();
    ~CGameModel();

    virtual void Tick(float DeltaTime) override;

    friend class CGameView;
    friend class CGameController;
};


#endif //PLATFORMER_CGAMEMODEL_H
