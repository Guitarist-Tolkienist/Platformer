#ifndef PLATFORMER_MATH_H
#define PLATFORMER_MATH_H

namespace _2D {

    struct SVector_2D {
        float m_X;
        float m_Y;

        SVector_2D() :
                m_X(0),
                m_Y(0) {}

        SVector_2D(float x, float y) :
                m_X(x),
                m_Y(y) {}

        SVector_2D(const SVector_2D &Dot) {
            m_X = Dot.m_X;
            m_Y = Dot.m_Y;
        }
    };

}

#endif //PLATFORMER_MATH_H
