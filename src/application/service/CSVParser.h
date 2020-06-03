#ifndef SRC_CSVPARSER_H
#define SRC_CSVPARSER_H

#include <string>
#include <vector>

#include "../data/Cleaner.h"
#include "../data/Measure.h"
#include "../data/actor/Provider.h"
#include "../data/actor/PrivateIndividual.h"
#include "../data/Sensor.h"
#include "../data/Catalog.h"

class CSVParser {

public:

    static void ReadCleanersCSV(const std::string &filename, Catalog &catalog);

    static void ReadMeasuresCSV(const std::string &filename, Catalog &catalog);

    static void ReadProvidersCSV(const std::string &filename, Catalog &catalog);

    static void ReadSensorsCSV(const std::string &filename, Catalog &catalog);

    static void ReadPrivateIndividualsCSV(const std::string &filename, Catalog &catalog);

};


#endif //SRC_CSVPARSER_H
