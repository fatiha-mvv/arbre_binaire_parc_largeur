// arbre_binaire_parc_largeur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <chrono> // Pour mesurer le temps
using namespace std;
using namespace std::chrono;
#include "Tree.h"


int main()
{
    //---------------------- Construction d'arbre-----------------//
    // creer un arbre
    Tree* arbre = new Tree(10);

     //------------------------- Mesure du temps d'insertion -------------------- //
    auto startInsert = high_resolution_clock::now();
    //insertion de nouvelles valeurs
    arbre->insertAleatoireParNiveau(4);
    arbre->insertAleatoireParNiveau(15);
    arbre->insertAleatoireParNiveau(8);
    arbre->insertAleatoireParNiveau(20);
    arbre->insertAleatoireParNiveau(17);
    auto stopInsert = high_resolution_clock::now();
    auto durationInsert = duration_cast<microseconds>(stopInsert - startInsert);
    cout << "Temps d'insertion des valeurs : " << durationInsert.count() << " microsecondes." << endl;

    //------------------------- Mesure du temps de parcours BFS-------------------- //
    auto startBFS = high_resolution_clock::now();
    //parcours de l'arbre BFS
    cout << "\nParcours en Largeur BFS " << endl;
    arbre->BFS();
    auto stopBFS = high_resolution_clock::now();
    auto durationBFS = duration_cast<microseconds>(stopBFS - startBFS);
    cout << "\nTemps de parcours en largeur BFS : " << durationBFS.count() << " microsecondes." << endl;


    //------------------------- Mesure du temps de recherche-------------------- //
    auto startSearch = high_resolution_clock::now();
    //chercher une valeur
    if (arbre->chercherVal(99))
        cout << " \noui, la valeur existe dans l'arbre " << endl;
    else
        cout << " \nnon, la valeur n'existe pas dans l'arbre " << endl;
    auto stopSearch = high_resolution_clock::now();
    auto durationSearch = duration_cast<microseconds>(stopSearch - startSearch);
    cout << "Temps de recherche de la valeur qui n'existe pas : " << durationSearch.count() << " microsecondes." << endl;
    //--------------------------------------------------------------------------- //

    //affichage prefixe
    cout << "\nAffichage Prefixe " << endl;
    arbre->printTreePrefixe();

    //affichage infixe
    cout << "\nAffichage Infixe " << endl;
    arbre->printTreeInfixe();

    //affichage infixe
    cout << "\nAffichage Postfixe " << endl;
    arbre->printTreePostfixe();

}
