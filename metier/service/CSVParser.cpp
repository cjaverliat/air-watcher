#include "CSVParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

const int NB_CLEANERS = 2;
const int NB_SENSORS = 100;
const int NB_MEASURES = 146000 / 4;

const int NB_PROVIDERS = 2;
const int NB_USERS = 2;

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

void printProgress(string prefix, float progress) {

    int barWidth = 70;
    progress = ceil(progress * 100) / 100;

    cout << left << setw(35) << prefix << setw(barWidth + 10);
    cout << setw(1) << "[";

    int pos = barWidth * progress;

    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %";
    cout << flush;
}

void CSVParser::ReadCleanersCSV(const std::string &filename, Catalog &catalog) {

    catalog._cleaners.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit(1);
    }

    cout << endl;
    float progress = 0.0;
    printProgress("\rLecture des cleaners ", 0.0);

    Cleaner cleaner;
    string lineInput;

    while (file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> cleaner;
            catalog._cleaners.push_back(cleaner);
            progress += 1.0 / NB_CLEANERS;
            printProgress("\rLecture des cleaners ", progress);
        }
    }

} //----- Fin de ReadCleanersCSV

void CSVParser::ReadMeasuresCSV(const std::string &filename, Catalog &catalog) {

    catalog._measures.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit(1);
    }

    cout << endl;
    float progress = 0.0;
    printProgress("\rLecture des mesures ", 0.0);

    Measure measure(&catalog);
    string lineInput;
    bool invalidEntry;

    // Lecture de 4 lignes d'un coup (O3, NO2, SO2, PM10)

    while (file.good()) {
        stringstream ss;
        invalidEntry = false;

        for (unsigned i = 0; i < 4; ++i) {
            getline(file, lineInput, '\n');
            if (!lineInput.empty()) {
                ss << lineInput + '\n';
            } else {
                invalidEntry = true;
                break;
            }
        }

        if (!invalidEntry) {
            ss >> measure;
            catalog._measures.push_back(measure);
            progress += 1.0 / NB_MEASURES;
            printProgress("\rLecture des mesures ", progress);
        }
    }

} //----- Fin de ReadMeasuresCSV

void CSVParser::ReadProvidersCSV(const std::string &filename, Catalog &catalog) {

    catalog._providers.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit(1);
    }

    cout << endl;
    float progress = 0.0;
    printProgress("\rLecture des providers ", 0.0);

    Provider provider(&catalog);
    string lineInput;

    while (file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> provider;
            catalog._providers.push_back(provider);
            progress += 1.0 / NB_PROVIDERS;
            printProgress("\rLecture des providers ", progress);
        }
    }

} //----- Fin de ReadProvidersCSV

void CSVParser::ReadSensorsCSV(const std::string &filename, Catalog &catalog) {

    catalog._sensors.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit(1);
    }

    cout << endl;
    float progress = 0.0;
    printProgress("\rLecture des sensors ", 0.0);

    Sensor sensor;
    string lineInput;

    while (file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> sensor;
            catalog._sensors.push_back(sensor);
            progress += 1.0 / NB_SENSORS;
            printProgress("\rLecture des sensors ", progress);
        }
    }

} //----- Fin de ReadSensorsCSV

void CSVParser::ReadPrivateIndividualsCSV(const std::string &filename, Catalog &catalog) {

    catalog._privateIndividuals.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier " << filename << endl;
        exit(1);
    }

    cout << endl;
    float progress = 0.0;
    printProgress("\rLecture des private individuals ", 0.0);

    PrivateIndividual privateIndividual(&catalog);
    string lineInput;

    while (file.good()) {
        getline(file, lineInput, '\n');

        if (!lineInput.empty()) {
            stringstream ss(lineInput + '\n');
            ss >> privateIndividual;
            catalog._privateIndividuals.push_back(privateIndividual);
            progress += 1.0 / NB_USERS;
            printProgress("\rLecture des private individuals ", progress);
        }
    }

} //----- Fin de ReadPrivateIndividualsCSV

CSVParser::CSVParser() {
#ifdef MAP
    cout << "Appel au constructeur de <CSVParser>" << endl;
#endif
} //----- Fin de CSVParser


CSVParser::~CSVParser() {
#ifdef MAP
    cout << "Appel au destructeur de <CSVParser>" << endl;
#endif
} //----- Fin de ~CSVParser