#ifndef SRC_CSVPARSER_H
#define SRC_CSVPARSER_H

#include <string>
#include <vector>

//#include "../metier/data/Attribute.h"
#include "../metier/data/Cleaner.h"
#include "../metier/data/Measure.h"
#include "../metier/acteurs/Provider.h"
#include "../metier/data/Sensor.h"
#include "../metier/acteurs/Privateindividual.h"

class CSVParser {

public:

    //static void ReadAttributesCSV (const std::string & filename, std::vector<Attribute> & attributes);

    static void ReadCleanersCSV (const std::string & filename, std::vector<Cleaner> & cleaners);

    static void ReadMeasuresCSV (const std::string & filename, std::vector<Measure> & measures);

    static void ReadProvidersCSV (const std::string & filename, std::vector<Provider> & providers);

    static void ReadSensorsCSV (const std::string & filename, std::vector<Sensor> & sensors);

    static void ReadPrivateIndividualsCSV (const std::string & filename, std::vector<PrivateIndividual> & privateIndividuals);

    CSVParser (const CSVParser & unCSVParser);

    CSVParser ();

    virtual ~CSVParser ();

};


#endif //SRC_CSVPARSER_H
