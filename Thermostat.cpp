#include "Thermostat.h"

#include <iostream>

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


// constructeur qui depend :
// SetZone(int i, GetMin()) / GetMin()
//contructeur initialise en mode automatique  (0) / affecte  10°C pour chaque zone / donne session= 0 pour entrer dans boucle
Thermostat::Thermostat()
{
    this->mode = 0;
    for(int i = 0; i < 3 ; i++)
    {
        this->SetZone(i, GetMin());
    }
    this->session = 0;
    this->tempManuel = 10;
}

Thermostat::~Thermostat()
{
    
}

int Thermostat::GetSession(){
    return session;
}

int Thermostat::GetMin(){
    return MIN;
}

int Thermostat::GetMax(){
    return MAX;
}

//methode retourne valeur dans case cible du tableau de zone en entrant indice correspondant
int Thermostat::GetZone(int indice){
    return zone[indice];
}

//methode qui modifie la valeur d'une case cible du tableau de zone en entrant indice de la case et la valeur à inserer
void Thermostat::SetZone(int indice, int temp){
    this->zone[indice] = temp;
}

int Thermostat::GetMode(){
    
    return mode;
}

//methode qui permet d'afficher le mode actuel du thermostat
//methode qui verifie la valeur dans l'attribut mode puis affiche l'appelation du mode 
void Thermostat::AffichMode(){
    
    //std::string nomMode;
    
    if(!mode)
    {
        cout << "AUTOMATIQUE" << endl;
        //nomMode = "AUTOMATIQUE";
    }
    else{
        cout << "MANUEL" << endl;
        //nomMode = "MANUEL";
    }
    
    //return nomMode;
}

//methode qui permet de passer du mode automatique au manuel et vise-versa
//methode verifie la valeur de l'attribut mode et l'inverse (0->1 ou 1->0)
void Thermostat::SetMode(){
    
    if(!this->mode)
    {
        this->mode = 1;
    }   
    else
    {
        this->mode = 0;
    }
}

void Thermostat::AfficheOption()
{
    cout << "Options" << endl;
    cout << " 0- Arreter le thermostat" << endl;
    cout << " 1- Definir le mode" << endl;
    cout << " 2- Ajuster la temperature" << endl;
    cout << " 3- Afficher le thermostat" << endl;
}

//methode qui depend : 
// AffichMode() / GetMode() / GetZone(int i) 
void Thermostat::AfficheThermo(){
    
    //boucle pour afficher la separation haute 
    for(int i = 0; i < 45 ; i++)
    {
        cout << "-";
    }
    
    cout << endl;
    cout << "- SUPER THERMOSTAT 8SIF109" << endl;
    cout << "- MODE : ";
    this->AffichMode();
    if(this->GetMode() == 0)
    {
        for(int i = 0; i < 3 ; i ++)
        {
            cout << "- Zone : " << i+1 << endl;
            cout << "    Temperature : " << this->GetZone(i) << endl;
        }
    }
    else
    {
        cout << "    Temperature : " << this->tempManuel << endl;
    }
    
    //boucle pour afficher la separation basse
    for(int i = 0; i < 45 ; i++)
    {
        cout << "-";
    }
    cout << endl;
}

//methode qui depend de AffichMode() / SetMode() / ChoixMode()
void Thermostat::ChoixMode(){
    
    char choixM;
    cout << "Mode actuel : ";
    this->AffichMode();
    cout << "  Definir le mode (M) ou (A)  : ";
    cin >> choixM;
    switch (choixM)
    {
        case 'M':
            cout << "MODE MANUEL CHOISI" << endl << endl;
            this->SetMode();
            break;
        case 'A':
            cout << "MODE AUTOMATIQUE CHOISI" << endl << endl;
            this->SetMode();
            break;
        default:
            cout << "Choix non reconnu. Veuillez saisir M ou A." << endl << endl;
            this->ChoixMode();
    }
}
//methode permettant d'arreter l'application themrostat 
//attention !! une fois arreter on reprend sur la partie 2
void Thermostat::Arreter(){
    
    this->session = 1;
    cout << "ARRET DU THERMOMETRE" << endl;
}
//methode qui depend de :
//AffichMode() / GetMode() / VerifZone() / VerifTemp() / SetZone() / SetTempManuel(int choixTemp)
void Thermostat::AjusterTemp(){
    
    int choixZone = -1;
   
    int choixTemp = 0;

    cout << "Mode actuel : " ;
    this->AffichMode();
    if(this->GetMode() == 0 )
    {
        //recursivite tant que la saisie de la zone n'est pas comprise entre 0 et 3 inclus 
        while(choixZone < 0 || choixZone > 3)
        {
            choixZone = this->VerifZone();
        }
        choixZone = choixZone -1;
        //recursivite tant que la saisie de température n'est pas dans la fourchette prevue
        while(choixTemp < 10 || choixTemp > 20)
        {
            choixTemp = this->VerifTemp(); 
        }
        this->SetZone(choixZone, choixTemp); 
    }
    else
    {
        //recursivite tant que la saisie  de température n'est pas dans la fourchette prevue
        while(choixTemp < 10 || choixTemp > 20)
        {
            choixTemp = this->VerifTemp(); 
        }
        this->SetTempManuel(choixTemp);
    }
}

int Thermostat::VerifZone(){
    
    int zone = 0;
    cout << "   Definir la zone (1), (2) ou (3)? : ";
    cin >> zone;
    if(zone < 1 || zone > 3)
    {
        cin.clear();
        cerr << "Error : Veuillez rentrer un NOMBRE !";
        cout << "Saisie incorrecte. Veuillez une zone comprise entre 1 et 3 inclus." << endl;
    }
    
    return zone;
}

// methode qui depend de : 
// GetMin() / GetMax()
int Thermostat::VerifTemp(){
    
    int temp = 0;
    cout << "   Definir la nouvelle temperature (" << this->GetMin() << "-" << this->GetMax() << ") : ";
    cin >> temp;
    if(temp < 10 || temp > 20)
    {
        cout << "Saisie incorrect. Veuillez rentrer une temperature entre 10 et 20." << endl;
    }

    return temp;
}

int Thermostat::GetTempManuel(){
    
    return tempManuel;
}

void Thermostat::SetTempManuel(int temp){
    
    this->tempManuel = temp;
}

ostream &operator<< (ostream& out, Thermostat& v)
{
    //boucle pour afficher la separation haute 
    for(int i = 0; i < 45 ; i++)
    {
        out << "-";
    }
    out << endl;
    out << "- SUPER THERMOSTAT 8SIF109" << endl;
    out << "- MODE : ";
    //v.AffichMode();
    v.AffichMode();
    if(v.GetMode() == 0)
    {
        for(int i = 0; i < 3 ; i ++)
        {
            out << "- Zone : " << i+1 << endl;
            out << "    Temperature : " << v.GetZone(i) << endl;
        }
    }
    else
    {
        out << "    Temperature : " << v.tempManuel << endl;
    }
    
    //boucle pour afficher la separation basse
    for(int i = 0; i < 45 ; i++)
    {
        out << "-";
    }
    out << endl;
	return out;
}

int Thermostat::VerifChoixMenu()
{
    int choixFini = -1;
    int choix = -1;
    cout << " .. Votre choix ? ";
    cin >> choix;
    
    choixFini = choix;
    
    return choixFini;
}
