#include <gtest/gtest.h>

#include "StandardTime.h"

TEST(TestStandardTime, DefaultConstructor) {
    std::chrono::system_clock c;
    time_t initial = c.to_time_t(c.now());

    opt::StandardTime current;

    EXPECT_GE(current.get_unix_time(), initial);
}

TEST(TestStandardTime, ParameterizedConstructor) {
    opt::StandardTime t(1730);
    EXPECT_EQ(1730, t.get_unix_time());
}

TEST(TestStandardTime, GetUnixTime) {
    opt::StandardTime t1(13658);
    opt::StandardTime t2(348);

    EXPECT_EQ(13658, t1.get_unix_time());
    EXPECT_EQ(348, t2.get_unix_time());

    EXPECT_GT(t1.get_unix_time(), t2.get_unix_time());
}

TEST(TestStandardTime, Format) {
    std::tm timestamp{};
    timestamp.tm_year = 2024 - 1900;
    timestamp.tm_mon = 10 - 1;
    timestamp.tm_mday = 9;
    timestamp.tm_hour = 10 - 1;
    timestamp.tm_min = 26;
    timestamp.tm_sec = 0;

    opt::StandardTime t(std::mktime(&timestamp));

    EXPECT_EQ("2024/10/09 10:26:00", t.format("%Y/%m/%d %H:%M:%S"));
}