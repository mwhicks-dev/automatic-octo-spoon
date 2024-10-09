#include <gtest/gtest.h>

#include "TickerData.h"

TEST(TestTickerData, Constructor) {
    opt::TickerData data("AAPL", "Apple", "2024/10/09 2:23:30", 228.97);
    EXPECT_EQ("AAPL", data.symbol);
    EXPECT_EQ("Apple", data.name);
    EXPECT_EQ("2024/10/09 2:23:30", data.timestamp);
    EXPECT_FLOAT_EQ(228.97, data.value);
}