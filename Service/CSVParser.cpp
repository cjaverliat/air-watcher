//
// Created by Nicolas on 06/05/2020.
//

#include "CSVParser.h"
#include <iostream>
#include <fstream>

void CSVParser::ReadAttributesCSV (std::string filename, std::vector<Attribute> & attributes)
{
    std::ifstream file(filename);
    Attribute attribute;
    file >> attribute; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> attribute;
        if(!file.good()) break;
        attributes.push_back(attribute);
    }

} //----- Fin de ReadAttributesCSV

void CSVParser::ReadCleanersCSV (std::string filename, std::vector<Cleaner> & cleaners)
{
    std::ifstream file(filename);
    Cleaner cleaner;
    file >> cleaner; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> cleaner;
        if(!file.good()) break;
        cleaners.push_back(cleaner);
    }

} //----- Fin de ReadCleanersCSV

CSVParser::CSVParser ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <CSVParser>" << endl;
#endif
} //----- Fin de CSVParser


CSVParser::~CSVParser ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <CSVParser>" << endl;
#endif
} //----- Fin de ~CSVParser