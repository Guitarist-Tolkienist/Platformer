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

void CGameController::HandleJoyStick(const sf::Event& Event) {
    if(sf::Joystick::isConnected(0)) {
        unsigned int buttonCount = sf::Joystick::getButtonCount(0);

        for (int i = 0; i < buttonCount; ++i) {
            if (sf::Joystick::isButtonPressed(0, i)) {
                std::cout << i << " is pressed of" << buttonCount << "\n";

                if (i == 3) {
                    m_GameModel->m_Player->ChangeYState(AxisYMovement::Jump);
                }
                if (i == 9) {
                    m_GameView->GetWindow().close();
                }
            }
        }

        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        if (x == 0.0) {
            m_GameModel->m_Player->ChangeXState(AxisXMovement::Static);
        }

        if (x < 0.0) {
            m_GameModel->m_Player->ChangeXState(AxisXMovement::Left);
        } else if (x > 0.0) {
            m_GameModel->m_Player->ChangeXState(AxisXMovement::Right);
        }

    }
}

void CGameController::HandleEvent(const sf::Event& Event) {
    HandleJoyStick(Event);

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
                    m_GameModel->m_Player->ChangeXState(AxisXMovement::Left);
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    m_GameModel->m_Player->ChangeXState(AxisXMovement::Right);
                    break;
                case sf::Keyboard::Space:
                    m_GameModel->m_Player->ChangeYState(AxisYMovement::Jump);
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
                    m_GameModel->m_Player->ChangeXState(AxisXMovement::Static);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
