#pragma once
#ifndef clipper_test_hpp
#define clipper_test_hpp

#include <gtest/gtest.h>
#include "../libs/viatordsp-core/core/dsp/Distortion/TestClipper.h"

namespace viator_tests
{
    TestClipper test_clipper;

    std::vector<float> test_buffer;

    void populate_test_buffer();
    bool test_buffer_for_zeros();
    bool test_buffer_for_dc();
}

#endif