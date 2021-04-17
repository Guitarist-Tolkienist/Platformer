#include "CHitBox.h"

// Constructor
CHitBox::CHitBox() :
    m_Position(0, 0),
    m_Scale(100, 100){}

CHitBox::CHitBox(const SVector_2D& Pos, const SVector_2D& Scale):
    m_Position(Pos),
    m_Scale(Scale) {}

SVector_2D CHitBox::GetPosition() const {
    return m_Position;
}

SVector_2D CHitBox::SetPosition(SVector_2D NewPos) {
    m_Position = NewPos;
}

SVector_2D CHitBox::GetScale() const {
    return m_Scale;
}

SVector_2D CHitBox::SetScale(SVector_2D NewScale) {
    m_Scale = NewScale;
}