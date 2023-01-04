#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <iostream>
#include <string>

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

class Thermostat
{
    
private:

//tableau de int permettant de stocker les temperatures pour les 3 zones pour le mode automatique 
int zone[3];
// int permettant de stocker la temperature pour le mode manuel 
int tempManuel;
// booleen qui permet de déterminer dans quel mode se trouve le thermostat
// 0 = mode automatique 1 = mode manuel
bool mode;
// minimal de la fourchette de temperatures saisies 
const int MIN = 10;
// maximal de la fourchette de temperatures saisies 
const int MAX = 20;
// fait fonctionner l'application et remettre en boucle le menu contextuel
//permet une sortie de boucle et la fermeture de l'application
int session;

public:
    Thermostat();
    ~Thermostat();
    int GetSession();
    //methode qui retourne le MIN de la fourchette de saisie des températures 
    int GetMin();
    //methode qui retourne le MAX la fourchette de saisie des temperature 
    int GetMax();
    //methode qui retourne la température d'une zone précise en donnant l'indice du tableau 
    int GetZone(int indice);
    //mehode qui modifie la tepérature d'une zone 
    void SetZone(int indice, int temp);
    //methode qui retourne le booleen symbolisant le mode 
    // 0 = automatique et 1 = manuel
    int GetMode();
    //methode qui verifie le numero de mode (0 ou 1) et qui affiche le nom du mode 
    void AffichMode();
    //methode qui modifie le mode
    // la methode verifie que le numero de mode actuel et le change en son inverse (0 -> 1 ou 1-> 0)
    void SetMode();
    //methode qui affiche les options du thermostat quand celui-ci est en marche 
    void AfficheOption();
    //affiche la situation actuel du thermotre 
    // modele/ mode / temperature 
    void AfficheThermo();
    //methode qui permet d'effecteur le choix du menu contextuel du thermostat
    //void Choix();
    //methode qui permet de changer de mode 
    void ChoixMode();
    //methode qui permet d'arreter l'application du thermostat
    void Arreter();
    //methode qui permet d'ajuster la temperature du mode automatique ou mode manuel 
    void AjusterTemp();
    //methode qui controle l'input de l'utilisateur 
    //concernant la sélection de la zone pour ajuster la temperature en mode automatique
    int VerifZone();
    //methode qui controle l'input de l'utilisateur 
    //concernant la saisie de la nouvelle temperature en mode automatique et manuel
    int VerifTemp();
    //methode qui permet de retourner la temprature en mode manuel 
    int GetTempManuel();
    // methode qui permet de modifier la temperature en mode manuel
    void SetTempManuel(int temp);
    friend ostream &operator<< (ostream&, Thermostat& thermo);
    int VerifChoixMenu();
    
};

#endif // THERMOSTAT_H
