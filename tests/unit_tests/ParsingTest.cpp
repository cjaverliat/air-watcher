#include "gtest/gtest.h"

#include "application/service/CSVParser.h"

TEST(ParsingTest, parseSensor) {

    Sensor sensor;

    stringstream ss;
    ss << "Sensor1;44;-1;Description of sensor\n";
    ss >> sensor;

    EXPECT_EQ(sensor.getId(), 1);
    EXPECT_EQ(sensor.getCoordinates().getLatitude(), 44);
    EXPECT_EQ(sensor.getCoordinates().getLongitude(), -1);
    EXPECT_EQ(sensor.getDescription(), "Description of sensor");
}

TEST(ParsingTest, parseMeasure) {

    Catalog catalog;
    Sensor sensor(0, "", {0, 0});
    catalog._sensors.push_back(sensor);

    Measure measure(&catalog);

    stringstream ss;
    ss << "2019-01-01 12:00:00;Sensor0;O3;63.5;\n"
          "2019-01-01 12:00:00;Sensor0;NO2;73.75;\n"
          "2019-01-01 12:00:00;Sensor0;SO2;27.5;\n"
          "2019-01-01 12:00:00;Sensor0;PM10;48.5;\n";
    ss >> measure;

    EXPECT_EQ(measure.getValueO3(), 63.5);
    EXPECT_EQ(measure.getValueNO2(), 73.75);
    EXPECT_EQ(measure.getValueSO2(), 27.5);
    EXPECT_EQ(measure.getValuePM10(), 48.5);
    EXPECT_EQ(measure.getDate(), toEpoch(2019, 1, 1, 12, 0, 0));
    EXPECT_EQ(measure.getSensor()->getId(), sensor.getId());
}

TEST(ParsingTest, parseUser) {

    Catalog catalog;
    PrivateIndividual user(&catalog);
    Sensor sensor(0, "", {0, 0});
    catalog._sensors.push_back(sensor);

    stringstream ss;
    ss << "User0;Sensor0;\n";
    ss >> user;

    EXPECT_EQ(user.getLogin(), "User0");
    EXPECT_EQ(user.getSensor()->getId(), sensor.getId());
}

TEST(ParsingTest, parseCleaner) {

    Catalog catalog;
    Cleaner cleaner;

    stringstream ss;
    ss << "Cleaner0;45.333333;1.333333;;2019-02-01 12:00:00;2019-03-01 00:00:00;\n";
    ss >> cleaner;

    EXPECT_EQ(cleaner.getId(), 0);
    EXPECT_EQ(cleaner.getCoordinates().getLatitude(), 45.333333);
    EXPECT_EQ(cleaner.getCoordinates().getLongitude(), 1.333333);
    EXPECT_EQ(cleaner.getCleanerStart(), toEpoch(2019, 2, 1, 12, 0, 0));
    EXPECT_EQ(cleaner.getCleanerStop(), toEpoch(2019, 3, 1, 0, 0, 0));
}

TEST(ParsingTest, parseProvider) {

    Catalog catalog;
    Provider provider(&catalog);
    Cleaner cleaner(0, "", 0, 0, {0, 0});
    catalog._cleaners.push_back(cleaner);

    stringstream ss;
    ss << "Provider0;Cleaner0;\n";
    ss >> provider;

    EXPECT_EQ(provider.getLogin(), "Provider0");
    EXPECT_EQ(provider.getCleaner()->getId(), cleaner.getId());
}

