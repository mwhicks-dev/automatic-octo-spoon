#include <gtest/gtest.h>

#include "TickerQueue.h"

TEST(TestTickerQueue, Constructor) {
    EXPECT_NO_THROW({
        opt::TickerQueue("some_format_string");
    });
}

TEST(TestTickerQueue, BasicWorkflow) {
    opt::TickerQueue tq("%Y/%m/%d %H:%M:%S");

    opt::Symbol symb("AAPL", "Apple");
    
    std::tm timestamp{};
    timestamp.tm_year = 2024 - 1900;
    timestamp.tm_mon = 10 - 1;
    timestamp.tm_mday = 9;
    timestamp.tm_hour = 10;
    timestamp.tm_min = 44;
    timestamp.tm_sec = 15;
    opt::StandardTime t(std::mktime(&timestamp));

    opt::Ticker ticker(symb, t, 227.56);

    tq.push_ticker(ticker);

    ASSERT_TRUE(tq.ticker_available());
    opt::TickerData data = tq.pop_data();
    ASSERT_FALSE(tq.ticker_available());

    EXPECT_EQ("AAPL", data.symbol);
    EXPECT_EQ("Apple", data.name);
    EXPECT_EQ("2024/10/09 10:44:15", data.timestamp);
    EXPECT_FLOAT_EQ(227.56, data.value);
}

TEST(TestTickerQueue, BadFormatString) {
    opt::TickerQueue tq("fake format string");

    opt::Symbol symb("AAPL", "Apple");
    
    std::tm timestamp{};
    timestamp.tm_year = 2024 - 1900;
    timestamp.tm_mon = 10 - 1;
    timestamp.tm_mday = 9;
    timestamp.tm_hour = 10;
    timestamp.tm_min = 44;
    timestamp.tm_sec = 15;
    opt::StandardTime t(std::mktime(&timestamp));

    opt::Ticker ticker(symb, t, 227.56);

    tq.push_ticker(ticker);
    opt::TickerData data = tq.pop_data();
    EXPECT_EQ("fake format string", data.timestamp);
}