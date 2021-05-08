#ifndef PLATFORMER_CGAMEMODEL_H
#define PLATFORMER_CGAMEMODEL_H

#include "CPlayer.h"
#include <chrono>
#include <algorithm>
#include <array>

// Forward declaration
class CGameView;
class CGameController;

const float WINDOW_WIDTH = 1300.f;
const float WINDOW_HEIGHT = 650.f;

class CGameModel: public IUpdatable{
    int players_quantity;

    CPlayer* m_Player;
protected:

    static const int NPC_QUANTITY =  1;
    std::array<CPlayer, NPC_QUANTITY> m_NPC;
public:
    CGameModel();
    ~CGameModel();

    virtual void Tick(float DeltaTime) override;

    friend class CGameView;
    friend class CGameController;
};


#endif //PLATFORMER_CGAMEMODEL_H
