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
    sf::Event Event;

    while (m_GameView->GetWindow().isOpen()) {
        while (m_GameView->GetWindow().pollEvent(Event)) {
            HandleEvent(Event);
        }

        m_GameView->Render();
    }
}

void CGameController::HandleEvent(const sf::Event& Event) {
    switch (Event.type) {
        case sf::Event::Closed:
            m_GameView->GetWindow().close();
            break;
        case sf::Event::KeyPressed:
            switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    m_GameView->GetWindow().close();
                    break;
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    m_GameModel->m_Player->Move(MovingDirection::Left);
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    m_GameModel->m_Player->Move(MovingDirection::Right);
                    break;
                case sf::Keyboard::Space:
                    m_GameModel->m_Player->Move(MovingDirection::Up);
                    break;
                default:
                    break;
            }
            break;
        case sf::Event::KeyReleased:
            switch (Event.key.code) {
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    m_GameModel->m_Player->Move(MovingDirection::None);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
