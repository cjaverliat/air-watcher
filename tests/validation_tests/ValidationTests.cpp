#include <application/service/CSVParser.h>
#include <application/data/actor/Decider.h>
#include "gtest/gtest.h"

#include "application/service/Services.h"

TEST(ValidationTest, CleanerImpactScenario) {
    Catalog catalog;
    std::cout << "Reading test inputs..." << std::endl;
    CSVParser::ReadSensorsCSV("../../resources/tests/sensors.csv", catalog),
    CSVParser::ReadCleanersCSV("../../resources/tests/cleaners.csv", catalog);
    CSVParser::ReadMeasuresCSV("../../resources/tests/measurements.csv", catalog);
    CSVParser::ReadProvidersCSV("../../resources/tests/providers.csv", catalog);
    std::cout << std::endl << "Finished reading inputs." << std::endl;

    ASSERT_GE(catalog.getCleaners().size(), 2);

    Services services(catalog);

    std::pair<double, double> impact1 = services.computeCleanerImpact(catalog.getCleaners().at(0));
    std::pair<double, double> impact2 = services.computeCleanerImpact(catalog.getCleaners().at(1));

    EXPECT_NEAR(impact1.first, 27.9954, 10e-3); // Impact radius
    EXPECT_NEAR(impact1.second, 1, 10e-3); // Mean improvement
    EXPECT_EQ(impact2.first, 0);
    EXPECT_EQ(impact2.second, 0);
}

TEST(ValidationTest, MeanAirQualityScenario) {
    Catalog catalog;
    std::cout << "Reading test inputs..." << std::endl;
    CSVParser::ReadSensorsCSV("../../resources/tests/sensors.csv", catalog),
    CSVParser::ReadMeasuresCSV("../../resources/tests/measurements.csv", catalog);
    std::cout << "Finished reading inputs." << std::endl;

    Decider decider = Decider("Decider", "deciderpassword");

    Services services(catalog);

    double m1 = services.meanAirQuality({0, 0}, 0, toEpoch(2020, 6, 2, 12, 0, 0));
    double m2 = services.meanAirQuality({44, -1}, 5, toEpoch(2020, 6, 2, 12, 0, 0));

    EXPECT_EQ(m1, -1);
    EXPECT_EQ(m2, 3);

    double m3 = services.meanAirQuality({48.8501039, 2.3365324}, 0, toEpoch(2018, 6, 2, 12, 0, 0), toEpoch(2020, 6, 2, 12, 0, 0));
    double m4 = services.meanAirQuality({44, -1}, 5, toEpoch(2018, 6, 2, 12, 0, 0), toEpoch(2020, 6, 2, 12, 0, 0));

    EXPECT_EQ(m3, -1);
    EXPECT_NEAR(m4, 5.33333, 10e-5);
}