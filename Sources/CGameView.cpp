#include "CGameView.h"
#include <sstream>


CGameView::CGameView(CGameModel* Model) :
    m_GameModel(Model),
    m_View(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)){
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

sf::RenderWindow& CGameView::GetWindow() {
    return m_Window;
}

void CGameView::Render() {
    m_Window.clear();

    m_GameModel->Tick(m_DeltaTime);

    // Draw Regular Stuff
    ChangeViewCenter();
    m_Window.setView(m_View);
    m_Window.draw(*this);

    // Draw UI
    DrawUI();

    m_Window.display();

    sf::sleep(sf::seconds(1.0/60));
}

void CGameView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    m_GameModel->m_EarthPlatform->draw(target, states);

    target.draw(*m_GameModel->m_Player, states);

    for (int i = 0; i < CGameModel::NPC_QUANTITY; ++i) {
        target.draw(m_GameModel->m_NPC[i], states);
    }

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

void CGameView::DrawUI() {
    m_Window.setView(m_Window.getDefaultView());

    // todo change signature
    UpdateTime();

    if (m_bDrawFPS) {
        drawFPS();
    }
}

void CGameView::ResizeView() {
    float AspectRatio = float(m_Window.getSize().x)/float(m_Window.getSize().y);

    m_View.setSize(WINDOW_HEIGHT * AspectRatio, WINDOW_HEIGHT);
}

void CGameView::ChangeViewCenter() {
    sf::Vector2f ViewCenter(m_GameModel->m_Player->GetLocation().X, m_GameModel->m_Player->GetLocation().Y);

    ViewCenter.x += m_GameModel->m_Player->GetScale().X / 2;

    // CLAMP THE VIEW IN LEVEL WIDTH
    if(ViewCenter.x + m_View.getSize().x/2 > LEVEL_WIDTH) {
        ViewCenter.x = m_View.getCenter().x;
    }
    if(ViewCenter.x < WINDOW_WIDTH/2) {
        ViewCenter.x = m_View.getCenter().x;
    }

    ViewCenter.y += m_GameModel->m_Player->GetScale().Y / 2 - 200;

    m_View.setCenter(ViewCenter);
}


// FLAGS
void CGameView::ToggleFPS() {
    m_bDrawFPS = !m_bDrawFPS;
}

