#include "my_tests.h"
#include <gtest/gtest.h>

namespace viator_tests
{

    float test_buffer(float sample_xn)
    {
        // auto test_value = test_clipper.processSample(sample_xn);
        // auto rectified_value = std::abs(test_value);
        // return rectified_value >= 0.0f && rectified_value <= 1.0f;
    }

    int GetMeaningOfLife()
    {
        return 42;
    }

    TEST(TestTopic, TrivialEquality)
    {
        EXPECT_EQ(true, true);
    }

}
