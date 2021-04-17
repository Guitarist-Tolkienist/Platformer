#ifndef PLATFORMER_CHITBOX_H
#define PLATFORMER_CHITBOX_H

#include "SFML/Graphics.hpp"
#include "MATH.h"

using namespace _2D;

const int HITBOX_SCALE_DEFAULT = 100;

class CHitBox : sf::Drawable{
    SVector_2D m_Position;

    // size of the Entity (i.e. 2D vector)
    SVector_2D m_Scale;
public:
    CHitBox();
    CHitBox(const SVector_2D&, const SVector_2D&);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    SVector_2D GetPosition() const;
    SVector_2D GetScale() const;

    SVector_2D SetPosition(const SVector_2D&);
    SVector_2D SetScale(const SVector_2D&);
};


#endif //PLATFORMER_CHITBOX_H
