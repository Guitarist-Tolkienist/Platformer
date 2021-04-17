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


// todo remove into other file
bool doOverlap(SVector_2D l1, SVector_2D r1, SVector_2D l2, SVector_2D r2) {
    // To check if either rectangle is actually a line
    // For example :  l1 ={-1,0}  r1={1,1}  l2={0,-1}
    // r2={0,1}

    if (l1.m_X == r1.m_X || l1.m_Y == r2.m_Y || l2.m_X == r2.m_X
        || l2.m_Y == r2.m_Y) {
        // the line cannot have positive overlap
        return false;
    }

    // If one rectangle is on left side of other
    if (l1.m_X >= r2.m_X || l2.m_X >= r1.m_X)
        return false;

    // If one rectangle is above other
    if (l1.m_Y <= r2.m_Y || l2.m_Y <= r1.m_Y)
        return false;

    return true;
}
void printDot(const SVector_2D dot) {
    std::cout << dot.m_X << ", " << dot.m_Y << "\n";
}
struct rect {
    float X1;
    float Y1;
    float X2;
    float Y2;
};

void CGameModel::Tick(float DeltaTime) {
    for (int i = 0; i < NPC_QUANTITY; ++i) {
        m_NPC[i].Tick(DeltaTime);
    }

    m_Player->Tick(DeltaTime);

    SVector_2D RectA = m_Player->GetLocation();
    SVector_2D RectA_size = m_Player->GetScale();
    SVector_2D RectB = m_NPC[0].GetLocation();
    SVector_2D RectB_size = m_NPC[0].GetScale();


    if (RectA.m_X + RectA_size.m_X >= RectB.m_X && RectA.m_X + RectA_size.m_X  <= RectB.m_X + RectB_size.m_X) {
        if (RectA.m_Y + RectA_size.m_Y >= RectB.m_Y && RectA.m_Y + RectA_size.m_Y  <= RectB.m_Y + RectB_size.m_Y) {
            std::cout << "overlap at " << RectA.m_X << "\n";
            m_Player->Move(MovingState::None);
        }

    }
}
