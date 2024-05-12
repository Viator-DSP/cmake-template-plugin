#ifndef utils_h
#define utils_h

#include <cmath>

namespace viator::dsp
{
    static class Decibels
    {
        public:
            static double db_to_gain(double db_input)
            {
                return std::pow(10, db_input * 0.05f);
            }
    };
}


#endif /* utils_h */
