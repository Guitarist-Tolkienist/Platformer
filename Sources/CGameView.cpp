#include "CGameView.h"
#include <sstream>

CGameView::CGameView(CGameModel* Model) : m_GameModel(Model) {
    Init();
}

CGameView::~CGameView() throw() {
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

    // test
    m_Frames2++;
    elapsed_time = clock1.getElapsedTime();
    time2 = elapsed_time.asSeconds();

//    std::cout << "\n DeltaTime = " << time2 - time1;
    if (time2 - time1 > 1) {
        m_FPS = m_Frames2 - m_Frames1;

        m_Frames1 = m_Frames2;
        time1 = time2;
    }

    // render text
    std::ostringstream buff;
    buff << m_FPS;
    std::string s3(buff.str());

    m_Text = sf::Text(std::string("FPS: " + s3) , CAssets::GetInstance().m_Font, 20);

    m_GameModel->Tick(time2);
    // test

    m_Window.draw(m_Text);
    m_Window.draw(*this);

    m_Window.display();
    sf::sleep(sf::seconds(0.0069));
}
void CGameView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_GameModel->m_Player, states);

    for (int i = 0; i < CGameModel::NPC_QUANTITY; ++i) {
        target.draw(m_GameModel->m_NPC[i], states);
    }
}

sf::RenderWindow& CGameView::GetWindow() {
    return m_Window;
}
