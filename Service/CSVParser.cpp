//
// Created by Nicolas on 06/05/2020.
//

#include "CSVParser.h"
#include <iostream>
#include <fstream>

void CSVParser::ReadAttributesCSV (const std::string & filename, std::vector<Attribute> & attributes)
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

void CSVParser::ReadCleanersCSV (const std::string & filename, std::vector<Cleaner> & cleaners)
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

void CSVParser::ReadMeasuresCSV (const std::string & filename, std::vector<Measure> & measures)
{
    std::ifstream file(filename);
    Measure measure;
    file >> measure; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> measure;
        if(!file.good()) break;
        measures.push_back(measure);
    }

} //----- Fin de ReadMeasuresCSV

void CSVParser::ReadProvidersCSV (const std::string & filename, std::vector<Provider> & providers)
{
    std::ifstream file(filename);
    Provider provider;
    file >> provider; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> provider;
        if(!file.good()) break;
        providers.push_back(provider);
    }

} //----- Fin de ReadProvidersCSV

void CSVParser::ReadSensorsCSV (const std::string & filename, std::vector<Sensor> & sensors)
{
    std::ifstream file(filename);
    Sensor sensor;
    file >> sensor; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> sensor;
        if(!file.good()) break;
        sensors.push_back(sensor);
    }

} //----- Fin de ReadSensorsCSV

void CSVParser::ReadPrivateIndividualsCSV(const std:: & filename, std::vector<PrivateIndividual> & privateIndividuals)
{
    std::ifstream file(filename);
    PrivateIndividual privateIndividual;
    file >> privateIndividual; //On lit l'en-tête que l'on n'ajoute pas à la collection
    while(file.good())
    {
        file >> privateIndividual;
        if(!file.good()) break;
        privateIndividuals.push_back(privateIndividual);
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