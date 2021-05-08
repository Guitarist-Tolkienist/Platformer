#ifndef PLATFORMER_CMAPOBJECT_H
#define PLATFORMER_CMAPOBJECT_H

#include "CHitBox.h"

class CMapObject: public sf::Drawable {
    CHitBox m_HitBox;

    // APPEARANCE
    sf::Texture* m_Texture;
    sf::Sprite* m_Sprite;

protected:
    void SetLocation(const SVector_2D& NewLocation);
    void SetSprite(const char*);

public:
    CMapObject(const CHitBox& HitBox, const char* spriteFilename);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //PLATFORMER_CMAPOBJECT_H
