#include "clipper-test.h"

namespace viator_tests
{

void populate_test_buffer()
{
    test_buffer.clear();
    test_buffer.reserve(50000);

    for (int i = 0; i < 25000; ++i)
    {
        test_buffer.push_back(static_cast<float>(i + 1) * 0.0001f);
        test_buffer.push_back(static_cast<float>(i + 1) * -0.0001f);
    }
}

bool test_buffer_for_zeros()
{
    float current_sample = 0.0f;
    
    // run test 50000 times
    for (int i = 0; i < 50000; ++i)
    {
        test_clipper.randomize_parameters();

        for (auto& sample : test_buffer)
        {
            current_sample = test_clipper.processSample(test_buffer[sample]);

            if (current_sample == 0.0f)
            {
                return true;
            }
        }
    }

    return false;
}

bool test_buffer_for_dc()
{
    // run test 50000 times
    for (int i = 0; i < 50000; ++i)
    {
        test_clipper.randomize_parameters();

        for (int i = 0; i < test_buffer.size(); ++i)
        {
            test_buffer[i] = test_clipper.processSample(test_buffer[i]);
        }

        float sum = std::accumulate(test_buffer.begin(), test_buffer.end(), 0.0f);
        float dc_offset = sum / test_buffer.size();

        if (dc_offset > 0.01)
        {
            std::cout << "DC offset: " << dc_offset << std::endl;
            return true;
        }
    }

    return false;
}

TEST(TestTopic, ZeroBufferTest)
{
    populate_test_buffer();
    EXPECT_EQ(test_buffer_for_zeros(), false);
}

TEST(TestTopic, DCBufferTest)
{
    populate_test_buffer();
    EXPECT_EQ(test_buffer_for_dc(), false);
}

}
