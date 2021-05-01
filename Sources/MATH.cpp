#include "MATH.h"


namespace _2D {

    SVector_2D::SVector_2D() :
            m_X(0),
            m_Y(0) {}

    SVector_2D::SVector_2D(float x, float y) :
            m_X(x),
            m_Y(y) {}

    SVector_2D::SVector_2D(const SVector_2D& Vector_2D) {
        m_X = Vector_2D.m_X;
        m_Y = Vector_2D.m_Y;
    }

    // OPERATORS
    void SVector_2D::operator+=(const SVector_2D &Vector2) {
        this->m_X += Vector2.m_X;
        this->m_Y += Vector2.m_Y;
    }

    void SVector_2D::operator-=(const SVector_2D &Vector2) {
        this->m_X -= Vector2.m_X;
        this->m_Y -= Vector2.m_Y;
    }

    SVector_2D& SVector_2D::operator=(const SVector_2D &Vector2) {
        this->m_X = Vector2.m_X;
        this->m_Y = Vector2.m_Y;
        return *this;
    }

}