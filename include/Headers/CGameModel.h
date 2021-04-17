#ifndef PLATFORMER_CGAMEMODEL_H
#define PLATFORMER_CGAMEMODEL_H

#include "CPlayer.h"
#include <chrono>
#include <algorithm>
#include <array>


class CGameView;
class CGameController;

class CGameModel {
    int players_quantity;

    CPlayer* m_Player;
protected:

    static const int NPC_QUANTITY =  1;
    std::array<CPlayer, NPC_QUANTITY> m_NPC;
//    CPlayer* m_NPC;
public:
    CGameModel();
    ~CGameModel();

    // todo inherit from some base class which implement Tick method
    void Tick(float DeltaTime);

    friend class CGameView;
    friend class CGameController;
};


#endif //PLATFORMER_CGAMEMODEL_H
