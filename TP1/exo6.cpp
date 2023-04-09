#include <iostream>

using namespace std;

struct Noeud
{
    int donnee;
    Noeud *suivant;
};

struct Liste
{
    Noeud *premier;
};

struct DynaTableau
{
    int *donnees;
    int capacite;
    int nbVal;
};

void initialise(Liste *liste)
{

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    liste->premier = NULL;
}

bool est_vide(const Liste *liste)
{
    if(liste->premier==NULL){
        return true;
    } else return false;
}

void ajoute(Liste *liste, int valeur)
{
    Noeud *nouveau = new Noeud;
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->donnee = valeur;

    /*Insertion du noeud au début de la liste*/
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void affiche(const Liste *liste)
{
    Noeud *actuel = liste->premier;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while (actuel != nullptr)
    {
        std::cout << actuel->donnee << std::endl;
        actuel = actuel->suivant;
    }
}

int recupere(const Liste *liste, int n)
{
    Noeud *actuel = liste->premier;
    int valeur = 0;
    while (actuel != nullptr){
            if(valeur==n){
                return actuel->donnee;
            }
        actuel = actuel->suivant;
        valeur++;
    }
    return -1;
}

int cherche(const Liste *liste, int valeur)
{
    Noeud *actuel = liste->premier;
    int n = 0;
    while (actuel != nullptr){
            if(actuel->donnee==valeur){
                return n+1;
            }
        actuel = actuel->suivant;
        n++;
    }
    if(actuel == nullptr){
        return -1;
    } else{
        return n;
    }

}

void stocke(Liste *liste, int n, int valeur)
{
    Noeud *actuel = liste->premier;
    int i =1;
    while (i!=n && actuel != nullptr){
        actuel = actuel->suivant;
        i++;
    }
    if(actuel != nullptr){
        actuel->donnee=valeur;
    }

}

/*Tableau*/

void ajoute(DynaTableau *tableau, int valeur)
{
    if(tableau->donnees==NULL){
        tableau->donnees= new int[1];
        tableau->donnees[0] =valeur;
        tableau->capacite=1;
    } else if(tableau->nbVal==tableau->capacite){
        tableau->capacite *=2;
        int *nouvTab = new int[tableau->capacite];
        for(int i = 0; i< tableau->nbVal;i++){
            nouvTab[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees;
        tableau->donnees = nouvTab;
    }
    tableau->donnees[tableau->nbVal] = valeur;
    tableau->nbVal++;
}

void initialise(DynaTableau *tableau, int capacite)
{
    tableau->donnees = new int[capacite];
    tableau->capacite = capacite;
}

bool est_vide(const DynaTableau *liste)
{
    return liste->donnees ==NULL;
}

void affiche(const DynaTableau *tableau)
{
    if (est_vide(tableau))
    {
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i<tableau->nbVal;i++){
        cout << tableau->donnees[i] << endl;
    }
}

int recupere(const DynaTableau *tableau, int n)
{
    if(n>=tableau->nbVal){
        return 0;
    } else{
        return tableau->donnees[n];
    }
}

int cherche(const DynaTableau *tableau, int valeur)
{
    int n=0;
    if(est_vide(tableau)){
        exit(EXIT_FAILURE);
    }
    while(!(valeur==tableau->donnees[n])){
        n++;
    }
    n++;
    return n;
}

void stocke(DynaTableau *tableau, int n, int valeur)
{
    int i=0;
    if(est_vide(tableau)){
        exit(EXIT_FAILURE);
    }
    while(i<(n-1)){
        i++;
    }
    tableau->donnees[i]=valeur;
}

// void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste *liste, int valeur)
{
    ajoute(liste, valeur);
}

// int retire_file(Liste* liste)
int retire_file(Liste *liste)
{
    Noeud *actuel = liste->premier;
    if(actuel!=NULL){
        int val = actuel->donnee;
        liste->premier = actuel->suivant;
        delete actuel;
        return val;
    } else{
        return -1;
    }
}

// void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste *liste, int valeur)
{
    ajoute(liste, valeur);
}

// int retire_pile(DynaTableau* liste)
int retire_pile(Liste *liste)
{
    Noeud *actuel = liste->premier;
    int val;

    if(actuel != NULL){
        if(actuel->suivant==NULL){
            val = actuel->donnee;
            delete actuel;
            liste->premier = NULL;
            return val;
        } else{
            while(actuel->suivant->suivant != NULL){
                actuel =actuel->suivant;
            }
            val = actuel->suivant->donnee;
            delete actuel->suivant;
            actuel->suivant = NULL;
            return val;
        }
    } else{
        return -1;
    }
}

int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i = 1; i <= 7; i++)
    {
        ajoute(&liste, i * 7);
        ajoute(&tableau, i * 5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i = 1; i <= 7; i++)
    {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while (!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while (!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
