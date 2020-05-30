#include "CSVParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    cout << "Lecture des cleaners... " << flush;

    catalog._cleaners.clear();
    std::ifstream file(filename);

    if(!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit (1);
    }

    Cleaner cleaner;
    string lineInput;

    while(file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> cleaner;
            catalog._cleaners.push_back(cleaner);
        }
    }

    cout << "OK" << endl;
} //----- Fin de ReadCleanersCSV

void CSVParser::ReadMeasuresCSV (const std::string & filename, Catalog & catalog)
{
    cout << "Lecture des mesures... " << flush;

    catalog._measures.clear();
    std::ifstream file(filename);

    if(!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit (1);
    }

    Measure measure(&catalog);
    string lineInput;
    bool invalidEntry;

    // Lecture de 4 lignes d'un coup (O3, NO2, SO2, PM10)

    while(file.good()) {
        stringstream ss;
        invalidEntry = false;

        for(unsigned i = 0; i < 4; ++i) {
            getline(file, lineInput, '\n');
            if (!lineInput.empty()) {
                ss << lineInput + '\n';
            } else {
                invalidEntry = true;
                break;
            }
        }

        if(!invalidEntry) {
            ss >> measure;
            catalog._measures.push_back(measure);
        }
    }

    cout << "OK" << endl;
} //----- Fin de ReadMeasuresCSV

void CSVParser::ReadProvidersCSV (const std::string & filename, Catalog & catalog)
{
    cout << "Lecture des providers... " << flush;

    catalog._providers.clear();
    std::ifstream file(filename);

    if(!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit (1);
    }

    Provider provider(&catalog);
    string lineInput;

    while(file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> provider;
            catalog._providers.push_back(provider);
        }
    }

    cout << "OK" << endl;

} //----- Fin de ReadProvidersCSV

void CSVParser::ReadSensorsCSV (const std::string & filename, Catalog & catalog)
{
    cout << "Lecture des sensors... " << flush;

    catalog._sensors.clear();
    std::ifstream file(filename);

    if(!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit (1);
    }

    Sensor sensor;
    string lineInput;

    while(file.good())
    {
        getline(file, lineInput, '\n');

        if(!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> sensor;
            catalog._sensors.push_back(sensor);
        }
    }

    cout << "OK" << endl;

} //----- Fin de ReadSensorsCSV

void CSVParser::ReadPrivateIndividualsCSV(const std::string & filename, Catalog & catalog)
{
    cout << "Lecture des private individuals... " << flush;

    catalog._privateIndividuals.clear();
    std::ifstream file(filename);

    if(!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit (1);
    }

    PrivateIndividual privateIndividual(&catalog);
    string lineInput;

    while(file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> privateIndividual;
            catalog._privateIndividuals.push_back(privateIndividual);
        }
    }

    cout << "OK" << endl;

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