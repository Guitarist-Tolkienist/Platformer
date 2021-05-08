#include "CGameModel.h"

CGameModel::CGameModel(): players_quantity(1) {
    SVector_2D PLayerScale = SVector_2D(150, 150);
    SVector_2D PLayerPos = SVector_2D(150, EARTH_LOCATION - PLayerScale.Y);

    m_EarthPlatform = new CHitBox();
    m_EarthPlatform->SetPosition(SVector_2D(0, EARTH_LOCATION));
    m_EarthPlatform->SetScale(SVector_2D(LEVEL_WIDTH, WINDOW_HEIGHT - EARTH_LOCATION));

    m_Player = new (std::nothrow) CPlayer(CHitBox(PLayerPos, PLayerScale));
    if (!m_Player) {
        std::cout << "Error during creating CGameModel (can't create m_Player)\n";
    }

    m_Player->m_RunningPlatform = m_EarthPlatform;

    for (int i = 0; i < NPC_QUANTITY; ++i) {
        PLayerPos.X += 200;
        PLayerPos.Y -= 50;
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

    if (m_Player->IsFalling() || m_Player->IsRunning()) {
        bool overlap = false;
        for (int i = 0; i < NPC_QUANTITY; ++i) {
            _2D::SRectangle R1 = {m_Player->GetLocation(), m_Player->GetLocation() + m_Player->GetScale()};
            _2D::SRectangle R2 = {m_NPC[i].GetLocation(), m_NPC[i].GetLocation() + m_NPC[i].GetScale()};

            if (_2D::DoRectanglesOverlap(R1, R2)) {
                m_Player->m_RunningPlatform = m_NPC[i].GetHitBox();
                overlap = true;
            }
        }

        if (!overlap) {
            m_Player->m_RunningPlatform = m_EarthPlatform;
        }
    }
}
