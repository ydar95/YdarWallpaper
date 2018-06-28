#include "TickCount.h"

TickCount::TickCount()
{
}

void TickCount::start(){
    this->m_start_clock=std::chrono::high_resolution_clock::now();
}

void TickCount::stop(){
    this->m_stop_clock=std::chrono::high_resolution_clock::now();
}

double TickCount::getSec(){
    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(m_stop_clock - m_start_clock);
    return time_span.count();
}
