#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include <queue> // on inclut la file


class Tree
{
private:
	int donnee; //la donnee de noeud
	Tree* left; //le fils gauche
	Tree* right; //le fils droit
public:
	//constructeur
	Tree(int valeur) : donnee(valeur), left(nullptr), right(nullptr) {}

    // fonction pour inserer une valeur (pour le cas d'un arbre binaire Ordonnée)
	void insertPourArbreOrdonne(int val);

	//fonction pour inserer une valeur de maniere aleatoire dans l'arbre
	void insertAleatoire(int val);

	//fonction pour inserer selon les niveaux (on insere a gauche puis a droite et on pass
	// au niveau suivant )
	void insertAleatoireParNiveau(int);

	//Parcourir en largeur
	void BFS() const;

	//chercher une valeur dans l'arbre
	bool chercherVal(int val);

	//afficher l'arbre infixe (parcours en profondeur)
	void printTreeInfixe()const;

	//afficher l'arbre prefixe (parcours en profondeur)
	void printTreePrefixe()const;

	//afficher l'arbre postfixe (parcours en profondeur)
	void printTreePostfixe()const;

	
	
	//destructeur
	~Tree();

};


