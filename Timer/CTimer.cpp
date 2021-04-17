#include "CTimer.h"

CTimer::CTimer() : m_beg(clock_t::now()) {};

void CTimer::reset() {
    m_beg = clock_t::now();
}

double CTimer::elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}