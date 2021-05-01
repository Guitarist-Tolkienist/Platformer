#include "CGameView.h"
#include <sstream>

CGameView::CGameView(CGameModel* Model) : m_GameModel(Model) {
    Init();
}

CGameView::~CGameView() {
    m_GameModel = nullptr;
}

bool CGameView::Init() {
    // todo window name
    m_Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");

    m_Text = sf::Text("Time: | FPS: ", CAssets::GetInstance().m_Font, 20);

    return true;
}

void CGameView::Render() {
    m_Window.clear();

    m_GameModel->Tick(m_DeltaTime);
    // todo change signature
    UpdateTime();
    drawFPS();

    m_Window.draw(*this);

    m_Window.display();

    sf::sleep(sf::seconds(1.0/60));
}
void CGameView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_GameModel->m_Player, states);

    for (int i = 0; i < CGameModel::NPC_QUANTITY; ++i) {
//        target.draw(m_GameModel->m_NPC[i], states);
    }
}

sf::RenderWindow& CGameView::GetWindow() {
    return m_Window;
}

void CGameView::drawFPS() {
    std::ostringstream buff;
    buff << m_FPS;
    std::string s3(buff.str());

    m_Text = sf::Text(std::string("FPS: " + s3) , CAssets::GetInstance().m_Font, 20);

    m_Window.draw(m_Text);
}

void CGameView::UpdateTime() {
    m_Frames2++;

    m_DeltaTime = clock1.getElapsedTime().asSeconds() - sTime2;
//    std::cout << "\nView:UpdateTime DeltaTIme = " << m_DeltaTime;
    sTime2 = clock1.getElapsedTime().asSeconds();

    if (sTime2 - sTime1 > 1) {
        m_FPS = float(m_Frames2 - m_Frames1);

        m_Frames1 = m_Frames2;
        sTime1 = sTime2;
    }

}
