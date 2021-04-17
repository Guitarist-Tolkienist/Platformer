#include "CGameController.h"

CGameController::CGameController(CGameModel* GameModel, CGameView* GameView):
    m_GameView(GameView),
    m_GameModel(GameModel)
    {
    }

CGameController::~CGameController() {
    m_GameView = nullptr;

    m_GameModel = nullptr;
}

void CGameController::Run() {
    sf::Event event;

    while (m_GameView->GetWindow().isOpen()) {
        while (m_GameView->GetWindow().pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_GameView->GetWindow().close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            m_GameView->GetWindow().close();
                            break;
                        case sf::Keyboard::Left:
                        case sf::Keyboard::A:
                            m_GameModel->m_Player->Move(MovingState::Left);
                            break;
                        case sf::Keyboard::Right:
                        case sf::Keyboard::D:
                            m_GameModel->m_Player->Move(MovingState::Right);
                            break;
                        case sf::Keyboard::Space:
                            m_GameModel->m_Player->Jump();
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Left:
                        case sf::Keyboard::A:
                        case sf::Keyboard::Right:
                        case sf::Keyboard::D:
                            m_GameModel->m_Player->Move(MovingState::None);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        m_GameView->Render();
    }
}