#include <gtest/gtest.h>

#include "TimeSeries.h"

TEST(TestTimeSeries, Constructor) {
    // create start, end times
    std::tm start_timestamp{};
    start_timestamp.tm_year = 2024 - 1990;
    start_timestamp.tm_mon = 10 - 1;
    start_timestamp.tm_mday = 8;
    start_timestamp.tm_hour = 9;
    start_timestamp.tm_min = 30;
    opt::StandardTime t0(std::mktime(&start_timestamp));
    
    std::tm end_timestamp{};
    end_timestamp.tm_year = 2024 - 1990;
    end_timestamp.tm_mon = 10 - 1;
    end_timestamp.tm_mday = 8;
    end_timestamp.tm_hour = 16;
    opt::StandardTime tf(std::mktime(&end_timestamp));

    // create symbol
    opt::Symbol symb("AAPL", "Apple");

    // create time series
    opt::TimeSeries ts(symb, t0, tf, 224.30, 225.98, 223.25, 225.77);

    EXPECT_EQ("2024/10/8 09:30:00", ts.get_start().format("%Y/%m/%d %H:%M:%S"));
    EXPECT_EQ("2024/10/8 04:00:00", ts.get_start().format("%Y/%m/%d %H:%M:%S"));

    EXPECT_EQ("AAPL", ts.get_symbol().get_symbol());
    EXPECT_EQ("Apple", ts.get_symbol().get_name());

    EXPECT_FLOAT_EQ(224.30, ts.get_open());
    EXPECT_FLOAT_EQ(225.98, ts.get_high());
    EXPECT_FLOAT_EQ(223.25, ts.get_low());
    EXPECT_FLOAT_EQ(225.77, ts.get_close());
}