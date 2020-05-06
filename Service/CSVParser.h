//
// Created by Nicolas on 06/05/2020.
//

#ifndef SRC_CSVPARSER_H
#define SRC_CSVPARSER_H

#include <string>
#include <vector>

#include "../Metier/Attribute"

class CSVParser {

public:

    static void ReadAttributesCSV (std::string filename, std::vector<Attribute> & attributes);

    CSVParser (const CSVParser & unCSVParser);

    CSVParser ();

    virtual ~CSVParser ();

};


#endif //SRC_CSVPARSER_H
