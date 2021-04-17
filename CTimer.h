#ifndef PLATFORMER_CTIMER_H
#define PLATFORMER_CTIMER_H

#include <chrono>

class CTimer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    CTimer();

    void reset();

    double elapsed() const;
};


#endif //PLATFORMER_CTIMER_H
