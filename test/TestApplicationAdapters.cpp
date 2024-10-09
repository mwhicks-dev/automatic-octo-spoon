#include <gtest/gtest.h>

#include "TickerManager.h"
#include "PriceAdapter.h"
#include "TickerAdapter.h"

TEST(TestApplicationAdapters, IntegrationTest) {
    // construct application data structures
    opt::TickerQueue tq("arbitrary timestamp");
    opt::TickerAdapter ta(tq);
    opt::TickerManager tm(ta);
    opt::PriceAdapter pa(tm);

    // generate tickers and their expected outputs (more or less)
    std::vector<std::tuple<std::string, std::string, float>> input_data;
    std::vector<opt::TickerData> output_data;

    {  // ticker 1
        input_data.push_back({"BGRA", "Booger Aids", 5232.45});
        output_data.push_back(opt::TickerData("BGRA", "Booger Aids", "arbitrary timestamp", 5232.45));
    }

    {  // ticker 2
        input_data.push_back({"BGRA", "Booger Aids", 7007.38});
        output_data.push_back(opt::TickerData("BGRA", "Booger Aids", "arbitrary timestamp", 7007.38));
    }

    {  // ticker 3
        input_data.push_back({"BGRA", "Booger Aids", 10645.82});
        output_data.push_back(opt::TickerData("BGRA", "Booger Aids", "arbitrary timestamp", 10645.82));
    }

    for (size_t i = 0; i < 3; i++) {
        std::tuple<std::string, std::string, float> input = input_data[i];
        opt::TickerData expected = output_data[i];

        pa.update_ticker(std::get<0>(input), std::get<1>(input), std::get<2>(input));
        size_t ctr = 0;
        while (tq.ticker_available()) {
            EXPECT_EQ(0, ctr);
            opt::TickerData actual = tq.pop_data();

            EXPECT_EQ(expected.symbol, actual.symbol);
            EXPECT_EQ(expected.name, actual.name);
            EXPECT_EQ(expected.timestamp, actual.timestamp);
            EXPECT_EQ(expected.value, actual.value);
        }
    }
}