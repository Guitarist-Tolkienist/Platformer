#ifndef PLATFORMER_CHITBOX_H
#define PLATFORMER_CHITBOX_H

#include "MATH.h"

using namespace _2D;

class CHitBox {
    SVector_2D m_Position;

    // size of the Entity (i.e. 2D vector)
    SVector_2D m_Scale;
public:
    CHitBox();
    CHitBox(const SVector_2D&, const SVector_2D&);

    SVector_2D GetPosition() const;
    SVector_2D GetScale() const;

    SVector_2D SetPosition(SVector_2D);
    SVector_2D SetScale(SVector_2D);
};


#endif //PLATFORMER_CHITBOX_H
