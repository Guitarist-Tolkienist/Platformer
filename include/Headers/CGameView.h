#ifndef PLATFORMER_CGAMEVIEW_H
#define PLATFORMER_CGAMEVIEW_H

#include "SFML/Graphics.hpp"
#include "CGameModel.h"
#include "CAssets.h"

const float WINDOW_WIDTH = 1000.f;
const float WINDOW_HEIGHT = 800.f;

class CGameView : public sf::Drawable, public sf::Transformable {
    CGameModel* m_GameModel;

    sf::RenderWindow m_Window;
    sf::Text m_Text;

    sf::Clock clock1;
    sf::Time elapsed_time;
protected:
    float m_FPS;
    int m_Frames1 = 0;
    int m_Frames2 = 0;

    float time1;
    float time2;
public:
    CGameView(CGameModel* Model);
    ~CGameView();

    sf::RenderWindow& GetWindow();
    bool Init();
    void Render();

public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //PLATFORMER_CGAMEVIEW_H
