#include "CSVParser.h"
#include <iostream>
#include <fstream>

/*void CSVParser::ReadAttributesCSV (const std::string & filename, std::vector<Attribute> & attributes)
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

} //----- Fin de ReadAttributesCSV*/

void CSVParser::ReadCleanersCSV (const std::string & filename, Catalog & catalog)
{
    catalog._cleaners.empty();
    std::ifstream file(filename);
    Cleaner cleaner;
    while(file.good())
    {
        file >> cleaner;
        if(!file.good()) break;
        catalog._cleaners.push_back(cleaner);
    }
} //----- Fin de ReadCleanersCSV

void CSVParser::ReadMeasuresCSV (const std::string & filename, Catalog & catalog)
{
    catalog._measures.empty();
    std::ifstream file(filename);
    Measure measure(&catalog);
    while(file.good())
    {
        file >> measure;
        if(!file.good()) break;
        catalog._measures.push_back(measure);
    }

} //----- Fin de ReadMeasuresCSV

void CSVParser::ReadProvidersCSV (const std::string & filename, Catalog & catalog)
{
    catalog._providers.empty();
    std::ifstream file(filename);
    Provider provider(&catalog);
    while(file.good())
    {
        file >> provider;
        if(!file.good()) break;
        catalog._providers.push_back(provider);
    }

} //----- Fin de ReadProvidersCSV

void CSVParser::ReadSensorsCSV (const std::string & filename, Catalog & catalog)
{
    catalog._sensors.empty();
    std::ifstream file(filename);
    Sensor sensor;
    while(file.good())
    {
        file >> sensor;
        if(!file.good()) break;
        catalog._sensors.push_back(sensor);
    }

} //----- Fin de ReadSensorsCSV

void CSVParser::ReadPrivateIndividualsCSV(const std::string & filename, Catalog & catalog)
{
    catalog._privateIndividuals.empty();
    std::ifstream file(filename);
    PrivateIndividual privateIndividual(&catalog);
    while(file.good())
    {
        file >> privateIndividual;
        if(!file.good()) break;
        catalog._privateIndividuals.push_back(privateIndividual);
    }

} //----- Fin de ReadPrivateIndividualsCSV

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