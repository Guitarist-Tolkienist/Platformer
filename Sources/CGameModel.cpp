#include "CGameModel.h"

CGameModel::CGameModel(): players_quantity(1) {
    SVector_2D PLayerScale = SVector_2D(150, 150);
    SVector_2D PLayerPos = SVector_2D(150, EARTH_LOCATION - PLayerScale.m_Y);

    m_Player = new (std::nothrow) CPlayer(CHitBox(PLayerPos, PLayerScale));
    if (!m_Player) {
        std::cout << "Error during creating CGameModel (can't create m_Player)\n";
    }

    for (int i = 0; i < NPC_QUANTITY; ++i) {
        PLayerPos.m_X += 200;
        m_NPC[i] = new (std::nothrow) CPlayer(CHitBox(PLayerPos, PLayerScale), "../Resources/imp.png");
    }
}
CGameModel::~CGameModel() {
    delete m_Player;
    m_Player = nullptr;

    // todo clear array
}

void CGameModel::Tick(float DeltaTime) {
    for (auto& NPC : m_NPC) {
        NPC.Tick(DeltaTime);
    }

    m_Player->Tick(DeltaTime);

}
