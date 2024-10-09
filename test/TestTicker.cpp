#include <gtest/gtest.h>

#include "Ticker.h"

TEST(TestTicker, Constructor) {
    // create StandardTime object
    std::tm timestamp{};
    timestamp.tm_year = 2024 - 1900;
    timestamp.tm_mon = 10 - 1;
    timestamp.tm_mday = 9;
    timestamp.tm_hour = 10 - 1;
    timestamp.tm_min = 44;
    timestamp.tm_sec = 15;
    opt::StandardTime t(std::mktime(&timestamp));

    // create symb
    opt::Symbol s("AAPL", "Apple");

    opt::Ticker tick(s, t, 227.56);

    EXPECT_EQ("AAPL", tick.get_symbol().get_symbol());
    EXPECT_EQ("Apple", tick.get_symbol().get_name());
    EXPECT_EQ("2024/10/09 10:44:15", tick.get_time().format("%Y/%m/%d %H:%M:%S"));
    EXPECT_FLOAT_EQ(227.56, tick.get_value());
}