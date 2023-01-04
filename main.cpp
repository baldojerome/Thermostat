#include "Thermostat.h"

#include <iostream>
#include <limits>

//BALJ17058609
//ATTENTION A PRENDRE EN COMPTE!!!
/*Le code de mon travail pour la partie 1 et et 2 se trouvent dans les même fichiers.
La PARTIE 1 permet de jouer toutes les fonctionnalités de l'application
entre l'affichage du thermostat, le choix du mode, choix des temperatures.
L'affichage comprend la surcharge << permettant de directement réaliser un cout << objet
POINTS PROBLEMATIQUES: actuellement l'application repond à toutes les spécifications techniques 
demandees dans le travail. Malheuresement mes verifications ne sont pas totales.

L'application controle la saisie de l'utilisateur sur:
- choix de l'option dans le menu contextuel 
- choix de la zone pour ajuster la temperature en mode automatique 
- choix de la temperature compris en MIN et MAX
- choix du mode manuel ou automatique

Par exemple le controle de la saisie pour le menu contextuel permet d'obliger l'utilisateur à saisir le bon numéro.
L'application fera le travail Si l'utilisateur saisit un chiffre. Par contre je n'arrive pas à inclure le controle 
dans le cas où l'utilisateur saisit un caractère (l'application bugue)

La PARTIE 2 est directement joué après la PARTIE 1 dans le main.cpp.
Elle utilise directement la fonction Afficher(T valeur) situé dans le main.cpp
J'ai simplement crée un objet Thermostat pour jouer l'affichage avec les autres pré-requis du travail. 
l'arret du thermostat n'est simulé que par un texte et bien sur la sortie de boucle 
enlevant les options d'affichages.*/ 

using namespace std;

//fonction avec template permettant de tout afficher
template <typename T> 
void Afficher (T valeur)
{
    cout << valeur << endl;
}
// ------ PARTIE 1 ---------
//le main comprend l'affichage du menu contextuel ainsi que la saisie et du controle de la saisie
int main()
{
    Thermostat thermos; 
    while (thermos.GetSession() != 1)
    {
        thermos.AfficheOption();
        int choixMenu = 22;
        while(choixMenu != 0 && choixMenu != 1 && choixMenu != 2 && choixMenu != 3)
        {
            choixMenu = thermos.VerifChoixMenu();
        }
        
        //le switch permet d'aiguiller vers la methode repondant au choix dans le menu contextuel
        switch (choixMenu)
        {
            case 0:
                thermos.Arreter();
                break;
            case 1:
                thermos.ChoixMode();
                break;
            case 2:
                thermos.AjusterTemp();
                break;
            case 3:
                // surcharge sur l'affichage de l'objet Thermostat
                cout << thermos; 
                break;
      }
    }
    
    // ------ PARTIE 2 ---------
    // creation d'un objet Thermostat pour test d'Afficher(T valeur)
    Thermostat partie2;
    
    cout << endl << endl << "--------- DEMONSTRATION PARTIE 2 --------" << endl;
    cout << "Thermostat partie2;" << endl;
    cout << "Afficher(242);" << endl;
    cout << "Afficher(2.42);" << endl;
    cout << "Afficher('bonjour');" << endl;
    cout << "Afficher(partie2);" << endl;
    
    cout << "------ LE RESULTAT :" << endl;
    cout << "AFFICHER INT : ";
    Afficher(242);
    cout << "AFFICHER FLOAT : ";
    Afficher(2.42);
    cout << "AFFICHER STRING : ";
    Afficher("bonjour");
    cout << "AFFICHER OBJET THERMOSTAT : " << endl;
    Afficher(partie2);
    
    
    
    return 0;
}