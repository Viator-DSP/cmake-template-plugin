// #include "clipper-test.h"

// namespace viator_tests
// {

// void populate_test_buffer()
// {
//     test_buffer.clear();
//     test_buffer.reserve(BLOCK_SIZE);

//     for (int i = 0; i < static_cast<int>(BLOCK_SIZE * 0.5); ++i) 
//     {
//         test_buffer.push_back((i + 1) * 0.0009f);
//         test_buffer.push_back((i + 1) * -0.0009f);
//     }
// }

// bool buffer_free_of_zero()
// {
//     float current_sample = 0.0f;
//     int num_zeros = 0;
    
//     // run test 50000 times
//     for (int i = 0; i < NUM_TEST_RUNS; ++i)
//     {
//         test_clipper.randomize_parameters();

//         num_zeros = 0;

//         for (auto& sample : test_buffer)
//         {
//             current_sample = test_clipper.processSample(test_buffer[sample]);

//             if (current_sample == 0.0f)
//             {
//                 num_zeros++;
//             }
//         }
//     }

//     return num_zeros < BLOCK_SIZE;
// }

// bool buffer_free_of_dc()
// {
//     for (int i = 0; i < NUM_TEST_RUNS; ++i)
//     {
//         test_clipper.randomize_parameters();

//         for (int i = 0; i < test_buffer.size(); ++i)
//         {
//             test_buffer[i] = test_clipper.processSample(test_buffer[i]);
//         }

//         float sum = std::accumulate(test_buffer.begin(), 
//         test_buffer.end(), 
//         0.0f);
        
//         float dc_offset = sum / test_buffer.size();

//         if (dc_offset > 0.01)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// bool buffer_free_of_repeats()
// {
//     populate_test_buffer();

//     std::unordered_map<float, int> frequencyMap;
//     int maxCount = 0;
//     float mostFrequent = std::numeric_limits<float>::quiet_NaN();
//     int count;

//     for (int i = 0; i < NUM_TEST_RUNS; ++i)
//     {
//         test_clipper.randomize_parameters();
//         frequencyMap.clear();

//         for (float num : test_buffer) 
//         {
//             count = ++frequencyMap[num];
            
//             if (count > maxCount) 
//             {
//                 maxCount = count;
//                 mostFrequent = num;
//                 _count = count;
//             }
//         }
//     }

//     most_frequent = mostFrequent;
//     return _count < BLOCK_SIZE;
// }


// TEST(TestTopic, ZeroBufferTest)
// {
//     populate_test_buffer();
//     EXPECT_EQ(buffer_free_of_zero(), true);
// }

// TEST(TestTopic, DCBufferTest)
// {
//     populate_test_buffer();
//     EXPECT_EQ(buffer_free_of_dc(), true);
// }

// TEST(TestTopic, RepeatingValueCheck)
// {
//     populate_test_buffer();
//     EXPECT_EQ(buffer_free_of_repeats(), true);
// }

// }
