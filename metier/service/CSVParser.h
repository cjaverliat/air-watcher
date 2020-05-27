#ifndef SRC_CSVPARSER_H
#define SRC_CSVPARSER_H

#include <string>
#include <vector>

//#include "../metier/data/Attribute.h"
#include "../data/Cleaner.h"
#include "../data/Measure.h"
#include "../acteurs/Provider.h"
#include "../data/Sensor.h"
#include "../acteurs/PrivateIndividual.h"
#include "../data/Catalog.h"

class CSVParser {

public:

    //static void ReadAttributesCSV (const std::string & filename, std::vector<Attribute> & attributes);

    static void ReadCleanersCSV (const std::string & filename, Catalog & catalog);

    static void ReadMeasuresCSV (const std::string & filename, Catalog & catalog);

    static void ReadProvidersCSV (const std::string & filename, Catalog & catalog);

    static void ReadSensorsCSV (const std::string & filename, Catalog & catalog);

    static void ReadPrivateIndividualsCSV (const std::string & filename, Catalog & catalog);

    CSVParser (const CSVParser & unCSVParser); // Not implemented to prevent unwanted use

    CSVParser ();

    virtual ~CSVParser ();

};


#endif //SRC_CSVPARSER_H
