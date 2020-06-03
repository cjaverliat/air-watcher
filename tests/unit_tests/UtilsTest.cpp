#include "gtest/gtest.h"

#include "utils/Utils.h"

TEST(Utils, toRadians) {
    EXPECT_EQ(toRadians(0), 0);
    EXPECT_EQ(toRadians(90), M_PI_2);
    EXPECT_EQ(toRadians(180), M_PI);
    EXPECT_EQ(toRadians(270), 3 * M_PI_2);
    EXPECT_EQ(toRadians(360), 2 * M_PI);
}

TEST(Utils, haversineDistance) {
    EXPECT_EQ(haversineDistance({40, 5}, {40, 5}), 0);
    EXPECT_NEAR(haversineDistance({58.1564, 20.2456}, {40.7486, -73.9864}), 6486.18, 10e-3);
    EXPECT_NEAR(haversineDistance({-58.1564, 20.2456}, {40.7486, 73.9864}), 12069.98, 10e-3);
}

TEST(Utils, toEpoch) {
    EXPECT_EQ(toEpoch(1970, 1, 1, 0, 0, 0), 0);
    EXPECT_EQ(toEpoch(2020, 6, 2, 19, 31, 58), 1591126318);
    EXPECT_EQ(toEpoch(2019, 12, 30, 8, 52, 22), 1577695942);
    EXPECT_EQ(toEpoch(3057, 2, 3, 1, 22, 17), 34305297737);
}
