#include <iostream>
#include <limits>
#include <chrono>
#include <iomanip>

#include "metier/service/CSVParser.h"
#include "metier/acteurs/Decider.h"
#include "metier/acteurs/SuperUser.h"
#include "metier/service/Services.h"
#include "utils/Utils.h"

using namespace std;

static Catalog catalog = Catalog();

void loadData();

void SelectPrivateIndividual();
void SelectProvider();

void PrivateIndividualView(PrivateIndividual &privateIndividual);
void ProviderView(Provider &provider);
void DeciderView(Decider &decider);
void SuperUserView(SuperUser &superUser);

void AnalyseImpact(Cleaner &cleaner);

void ClearBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{

    cout << "Chargement des données en cours, veuillez patienter." << endl;

    clock_t loadStart = clock();
    loadData();
    double duration = double(clock() - loadStart) / CLOCKS_PER_SEC;

    cout << "\r " << endl << "Données chargées avec succès en " << setprecision(4) << duration << "s." << endl << endl;

    Decider decider = Decider("Decider", "deciderpassword");
    SuperUser superUser = SuperUser("SuperUser", "superuserpassword");

    unsigned int commande = 0;
    cout << "Avec quel compte voulez-vous vous connecter ?" << endl
         << endl;
    for (;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Individu privé" << endl
             << "-- (2) Fournisseur d'AirCleaner" << endl
             << "-- (3) Agence Gouvernementale" << endl
             << "-- (4) Administrateur (SuperUser)" << endl
             << "-- (5) Sortir" << endl;
        cin >> commande;
        switch (commande)
        {
            case 1:
                SelectPrivateIndividual();
                break;
            case 2:
                SelectProvider();
                break;
            case 3:
                DeciderView(decider);
                break;
            case 4:
                SuperUserView(superUser);
                break;
            case 5:
                cout << "Fermeture ..." << endl;
                return 0;
            default:
                cerr << "Commande inconnue." << endl;
                ClearBuffer();
                break;
        }
    }

    return 0;
}

void loadData() {
    CSVParser::ReadSensorsCSV("resources/sensors.csv", catalog);
    CSVParser::ReadCleanersCSV("resources/cleaners.csv", catalog);
    CSVParser::ReadMeasuresCSV("resources/measurements.csv", catalog);
    CSVParser::ReadPrivateIndividualsCSV("resources/users.csv", catalog);
    CSVParser::ReadProvidersCSV("resources/providers.csv", catalog);
}

void PrivateIndividualView(PrivateIndividual &privateIndividual)
{
    unsigned int commande = 0;
    cout << "Bienvenue " << privateIndividual.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl
         << endl;
    for (;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Voir mon score" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch (commande)
        {
        case 1:
            cout << "Votre score est de : " << privateIndividual.getUserScore() << endl;
            break;
        case 2:
            cout << "Fermeture ..." << endl;
            return;
        default:
            cerr << "Commande inconnue." << endl;
            ClearBuffer();
            break;
        }
    }
    return;
}

void ProviderView(Provider &provider)
{
    int commande = 0;
    Cleaner *cleaner = provider.getCleaner();
    cout << "Bienvenue " << provider.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl
         << endl;
    for (;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Analyser l'impact de mes AirCleaners" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch (commande)
        {
        case 1:
            //TODO Analyser l'impact
            cout << "Cleaner : " << cleaner->getCoordinates().getLatitude() << " " << cleaner->getCoordinates().getLongitude() << endl;
            AnalyseImpact(*(cleaner));
            break;
        case 2:
            cout << "Fermeture ..." << endl;
            return;
        default:
            cerr << "Commande inconnue." << endl;
            ClearBuffer();
            break;
        }
    }
}

void getMeanAirQuality() {
    Services services(catalog);

    double latitude, longitude;
    double radius;

    cout << endl << "Entrez les coordonnées du centre de la zone à étudier:" << endl;
    cout << "Latitude: ";
    cin >> latitude;
    cout << "Longitude: ";
    cin >> longitude;
    cout << "Rayon de la zone (en km): ";
    cin >> radius;

    Coordinates center(toRadians(latitude), toRadians(longitude));

    unsigned int timeCommand;

    cout << endl << "Choix du type de moyenne :" << endl
         << "-- (1) Moyenne la plus récente" << endl
         << "-- (2) Moyenne à un moment fixé dans le temps" << endl
         << "-- (3) Moyenne sur un intervalle de temps" << endl;

    cin >> timeCommand;
    cout << endl;

    switch (timeCommand)
    {
        case 1: {
            time_t t = time(nullptr);
            double meanAirQuality = services.meanAirQuality(center, radius, t);

            if(meanAirQuality != -1) {
                cout << "Indice ATMO moyen le plus récent dans la zone: " << meanAirQuality << endl;
            }

            break;
        }
        case 2: {

            cout << "Entrez la date au format DD/MM/YYYY: " << endl;

            int day, month, year;
            cin >> day;
            cin.get();
            cin >> month;
            cin.get();
            cin >> year;

            time_t t = toEpoch(year, month, day, 23, 59, 0);

            double meanAirQuality = services.meanAirQuality(center, radius, t);

            if(meanAirQuality != -1) {
                cout << endl << "Indice ATMO moyen dans la zone le " << day << "/" << month << "/" << year << ": " << meanAirQuality << endl;
            }

            break;
        }
        case 3: {
            cout << "Entrez le début de l'intervalle au format DD/MM/YYYY: " << endl;

            int s_day, s_month, s_year;
            cin >> s_day;
            cin.get();
            cin >> s_month;
            cin.get();
            cin >> s_year;

            cout << "Entrez la fin de l'intervalle au format DD/MM/YYYY: " << endl;

            int e_day, e_month, e_year;
            cin >> e_day;
            cin.get();
            cin >> e_month;
            cin.get();
            cin >> e_year;

            time_t start = toEpoch(s_year, s_month, s_day, 23, 59, 0);
            time_t end = toEpoch(e_year, e_month, e_day, 23, 59, 0);

            double meanAirQuality = services.meanAirQuality(center, radius, start, end);

            if(meanAirQuality != -1) {
                cout << "Indice ATMO moyen dans la zone entre le " << s_day << "/" << s_month << "/" << s_year << " et le " << e_day << "/" << e_month << "/" << e_year << ": " << meanAirQuality << endl;
            }

            break;
        }
        default:
            cerr << "Commande inconnue." << endl;
            ClearBuffer();
            break;
    }

    cout << endl;
}

void DeciderView(Decider &decider)
{
    unsigned int commande = 0;
    cout << "Bienvenue " << decider.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl
         << endl;
    for (;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Calculer l'indice ATMO moyen dans une zone " << endl
             << "-- (2) Identifier les capteurs similaires " << endl
             << "-- (3) Sortir" << endl;
        cin >> commande;
        switch (commande)
        {
        case 1: {
            getMeanAirQuality();
            break;
        }
        case 2:
            //TODO Identifier les capteurs similaires
            break;
        case 3:
            cout << "Fermeture ..." << endl;
            return;
        default:
            cerr << "Commande inconnue." << endl;
            ClearBuffer();
            break;
        }
    }
}

void SuperUserView(SuperUser &superUser)
{
    int commande = 0;
    cout << "Bienvenue " << superUser.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl
         << endl;
    for (;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Mesurer la performance algorithmique" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch (commande)
        {
        case 1:
            //TODO Mesurer la performance
            break;
        case 2:
            cout << "Fermeture ..." << endl;
            return;
        default:
            cerr << "Commande inconnue." << endl;
            ClearBuffer();
            break;
        }
    }
}

void SelectPrivateIndividual() {
    unsigned int commande = 0;
    for (;;)
    {
        cout << "Choisissez l'individu privé souhaité" << endl;
        cout << "-- (0) Sortir" << endl;
        vector<PrivateIndividual> privateIndividuals = catalog.getPrivateIndividuals();
        for (unsigned i(0); i < privateIndividuals.size(); ++i)
        {
            cout << "-- (" << i + 1 << ") " << privateIndividuals[i].getLogin() << endl;
        }
        cin >> commande;

        if (commande == 0)
            return;

        if (commande < 1 || commande > privateIndividuals.size())
        {
            cout << "Commande erronée" << endl;
            continue;
        }

        PrivateIndividualView(privateIndividuals[commande - 1]);
    }
}

void SelectProvider() {
    unsigned int commande = 0;
    for(;;)
    {
        cout << "Choisissez le fournisseur d'AirCleaners souhaité" << endl;
        cout << "-- (0) Sortir" << endl;
        vector<Provider> providers = catalog.getProviders();
        for (unsigned i(0); i < providers.size(); ++i)
        {
            cout << "-- (" << i + 1 << ") " << providers[i].getLogin() << endl;
        }
        cin >> commande;

        if (commande == 0)
            return;

        if (commande < 1 || commande > providers.size())
        {
            cout << "Commande erronée" << endl;
            continue;
        }

        ProviderView(providers[commande - 1]);
    }
}

void AnalyseImpact(Cleaner &cleaner) {
    Services services(catalog);
    std::pair<double,double> impact = services.computeCleanerImpact(cleaner);
    cout << "Rayon d'impact du cleaner " << cleaner.getId() << " : " << impact.first << endl;
    cout << "L'indice ATMO a été modifié en moyenne de : " << impact.second << endl;
}
