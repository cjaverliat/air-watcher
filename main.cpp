#include <iostream>
#include <limits>

#include "metier/service/CSVParser.h"
#include "metier/data/Catalog.h"
#include "metier/acteurs/PrivateIndividual.h"
#include "metier/acteurs/Provider.h"
#include "metier/acteurs/Decider.h"
#include "metier/acteurs/SuperUser.h"

using namespace std;

static Catalog catalog = Catalog();

void SelectPrivateIndividual(Catalog & catalog);
void SelectProvider(Catalog & catalog);

void PrivateIndividualView(PrivateIndividual & privateIndividual);
void ProviderView(Provider & provider);
void DeciderView(Decider & decider);
void SuperUserView(SuperUser & superUser);

void ClearBuffer()
{
    cin.clear ();
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
}

int main(){

    cout << "Chargement des données en cours, veuillez patienter." << endl << endl;
    //TODO Initialiser les données
    Decider decider = Decider("Decider", "deciderpassword");
    SuperUser superUser = SuperUser("SuperUser", "superuserpassword");
    cout << "Les données on bien été chargées." << endl << endl;

    int commande = 0;
    cout << "Avec quel compte voulez-vous vous connecter ?" << endl << endl;
    for(;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Individu privé" << endl
             << "-- (2) Fournisseur d'AirCleaner" << endl
             << "-- (3) Agence Gouvernementale" << endl
             << "-- (4) Administrateur (SuperUser)" << endl
             << "-- (5) Sortir" << endl;
        cin >> commande;
        switch(commande)
        {
            case 1:
                SelectPrivateIndividual(catalog);
                break;
            case 2:
                SelectProvider(catalog);
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

void PrivateIndividualView(PrivateIndividual & privateIndividual) {
    int commande = 0;
    cout << "Bienvenue " << privateIndividual.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl << endl;
    for(;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Voir mon score" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch(commande)
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

void ProviderView(Provider & provider) {
    int commande = 0;
    cout << "Bienvenue " << provider.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl << endl;
    for(;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Analyser l'impact de mes AirCleaners" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch(commande)
        {
            case 1:
                //TODO Analyser l'impact
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

void DeciderView(Decider & decider) {
    int commande = 0;
    cout << "Bienvenue" << decider.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl << endl;
    for(;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Calculer la moyenne " << endl //TODO améliorer les prompts
             << "-- (2) Identifier les capteurs similaires " << endl
             << "-- (3) Sortir" << endl;
        cin >> commande;
        switch(commande)
        {
            case 1:
                //TODO Calculer la moyenne
                break;
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

void SuperUserView(SuperUser & superUser) {
    int commande = 0;
    cout << "Bienvenue " << superUser.getLogin() << endl;
    cout << "Que voulez-vous faire ?" << endl << endl;
    for(;;)
    {
        cout << "Menu :" << endl
             << "-- (1) Mesurer la performance algorithmique" << endl
             << "-- (2) Sortir" << endl;
        cin >> commande;
        switch(commande)
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

void SelectPrivateIndividual(Catalog & catalog) {
    unsigned commande = 0;
    for(;;)
    {
        cout << "Choisissez l'individu privé souhaité" << endl;
        cout << "-- (0) Sortir" << endl;
        vector<PrivateIndividual> privateIndividuals = catalog.getPrivateIndividuals();
        for(unsigned i(0); i < privateIndividuals.size(); ++i) {
            cout << "-- (" << i+1 << ") " << privateIndividuals[i].getLogin() << endl;
        }
        cin >> commande;

        if(commande == 0)
            return;

        if(commande < 1 || commande > privateIndividuals.size()){
            cout << "Commande erronée" << endl;
            continue;
        }

        PrivateIndividualView(privateIndividuals[commande]);

    }
}

void SelectProvider(Catalog &catalog) {
    unsigned commande = 0;
    for(;;)
    {
        cout << "Choisissez le fournisseur d'AirCleaners souhaité" << endl;
        cout << "-- (0) Sortir" << endl;
        vector<Provider> providers = catalog.getProviders();
        for(unsigned i(0); i < providers.size(); ++i) {
            cout << "-- (" << i+1 << ") " << providers[i].getLogin() << endl;
        }
        cin >> commande;

        if(commande == 0)
            return;

        if(commande < 1 || commande > providers.size()){
            cout << "Commande erronée" << endl;
            continue;
        }

        ProviderView(providers[commande]);

    }
}
