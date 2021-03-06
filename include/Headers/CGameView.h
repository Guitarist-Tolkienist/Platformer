#ifndef PLATFORMER_CGAMEVIEW_H
#define PLATFORMER_CGAMEVIEW_H

#include "SFML/Graphics.hpp"
#include "CGameModel.h"
#include "CAssets.h"

class CGameView : public sf::Drawable, public sf::Transformable {
    CGameModel* m_GameModel;

    sf::RenderWindow m_Window;
    sf::View m_View;
    sf::Text m_Text;

    sf::Clock clock1;

    bool m_bDrawFPS = false;
protected:
    float m_FPS = 0.f;
    float m_DeltaTime = 0.0f;
    int m_Frames1 = 0;
    int m_Frames2 = 0;

    float sTime1 = 0.0f;
    float sTime2 = 0.0f;
public:
    CGameView(CGameModel* Model);
    ~CGameView();

    sf::RenderWindow& GetWindow();
    bool Init();
    void Render();

    void ChangeViewCenter();
    void ResizeView();

    // FLAGS
    void ToggleFPS();

private:
    void drawFPS();
    void UpdateTime();

public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void DrawUI();
};

#endif //PLATFORMER_CGAMEVIEW_H
