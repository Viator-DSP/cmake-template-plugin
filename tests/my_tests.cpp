#include <gtest/gtest.h>

namespace
{
    int GetMeaningOfLife() {  return 42; }
}

TEST(TestTopic, TrivialEquality)
{
    EXPECT_EQ(GetMeaningOfLife(), 42);
}