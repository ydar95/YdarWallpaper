#ifndef TICKTIME_H
#define TICKTIME_H

#include <chrono>
class TickCount
{

public:
    TickCount();
    void  start();
    void  stop();
    double getSec();
private:
    std::chrono::high_resolution_clock::time_point m_start_clock;
    std::chrono::high_resolution_clock::time_point m_stop_clock;
};

#endif // TICKTIME_H
