#include <gtest/gtest.h>

#include "Symbol.h"

TEST(TestSymbol, Constructor) {
    opt::Symbol symb("AAPL", "Apple");
    EXPECT_EQ("AAPL", symb.get_symbol());
    EXPECT_EQ("Apple", symb.get_name());
}