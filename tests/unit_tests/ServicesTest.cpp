#include "gtest/gtest.h"

#include "application/service/Services.h"

TEST(Services, computeATMOIndex) {

    // Setup
    Catalog catalog;
    Services services(catalog);
    Sensor sensor(0, "", {0, 0});

    Measure m1(0, 0, 0, 0, toEpoch(2019, 1, 1, 12, 0, 0), &sensor);
    Measure m2(63.5, 73.75, 27.5, 48.5, toEpoch(2019, 1, 1, 12, 0, 0), &sensor);

    EXPECT_EQ(services.computeATMOIndex(m1), 1);
    EXPECT_EQ(services.computeATMOIndex(m2), 2);
}
