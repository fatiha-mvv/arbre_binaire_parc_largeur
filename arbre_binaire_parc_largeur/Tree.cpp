#include "Tree.h"
#include <queue>

//----------> M�thode pour ins�rer une nouvelle valeur de mani�re al�atoire
void Tree::insertPourArbreOrdonne(int val)
{
    // si la valeur est plus petite que la donnee de noeud actuelle--> inserer a gauche
    if (val < donnee) 
    {
        // si il n y a pas un noeud fils gauche, on le cree avec la valeur donnee
        if (left == nullptr) 
        {
            left = new Tree(val);
        }
        else 
        {
            //sinon si existe, on l'insere recursivement dans le sous arbre gauche
            left->insertPourArbreOrdonne(val);
        }
    }
    // si la valeur est plus grande que la donnee de noeud actuelle--> inserer a droite
    else 
    {
        // si le noeud fils droit n'existe pas, on le cree
        if (right == nullptr) 
        {
            right = new Tree(val);
        }
        else 
        {
            // sinon si existe, on l'insere recursivement dans le sous arbre droit
            right->insertPourArbreOrdonne(val);
        }
    }
}


//------> insertion aleatoire soit a gauche ou a droite
void Tree::insertAleatoire(int val)
{
    // Choisir al�atoirement d'ins�rer � gauche ou � droite
    int randomChoice = rand() % 2;  // G�n�re 0 ou 1

    if (randomChoice == 0) 
    {
        // Ins�rer � gauche si le sous-arbre gauche est vide
        if (left == nullptr) 
        {
            left = new Tree(val);
        }
        else 
        {
            left->insertAleatoire(val);  // Sinon, ins�rer r�cursivement � gauche
        }
    }
    else 
    {
        // Ins�rer � droite si le sous-arbre droit est vide
        if (right == nullptr) 
        {
            right = new Tree(val);
        }
        else 
        {
            right->insertAleatoire(val);  // Sinon, ins�rer r�cursivement � droite
        }
    }
}


//---------> Fonction pour inserer a gauche puis a droit (jusqu'a remplir les niveaux)
void Tree::insertAleatoireParNiveau(int value) 
{
    std::queue<Tree*> q;
    q.push(this); //on insere la racine dans la file

    while (!q.empty()) 
    {
        Tree* current = q.front();  // recuperer la tete de la file
        q.pop();

        // verifier si le fils gauche est vide
        if (current->left == nullptr) 
        {
            current->left = new Tree(value);  // inserer dans le fils gauche
            return;
        }
        else 
        {
            q.push(current->left);  // ajouter le fils gauche � la file
        }

        // verifier si le fils droit est vide
        if (current->right == nullptr) 
        {
            current->right = new Tree(value);  // inserer dans le fils gauche
            return;
        }
        else 
        {
            q.push(current->right);  // ajouter le fils droit � la file
        }
    }
}



//----------> fonction pour afficher l'arbre (affichage infixe)
void Tree::printTreeInfixe() const
{
    if (left != nullptr) 
    {
        left->printTreeInfixe();  // afficher le noeud a gauche
    }
    cout << donnee << " ";    // afficher le noeud courant
    if (right != nullptr) 
    {
        right->printTreeInfixe();  // afficher le noeud a droite
    }
}



//----------> fonction pour afficher l'arbre (affichage postfixe)
void Tree::printTreePostfixe() const
{
    if (left != nullptr)
    {
        left->printTreePostfixe();  // afficher le noeud a gauche
    }
    if (right != nullptr)
    {
        right->printTreePostfixe();  // afficher le noeud a droite
    }
    cout << donnee << " ";    // afficher le noeud courant
}



//---------> fonction pour afficher l'arbre (affichage prefixe)
void Tree::printTreePrefixe() const
{
    cout << donnee << " ";    // afficher le noeud courant
    if (left != nullptr)
    {
        left->printTreePrefixe();  // afficher le noeud a gauche
    }
    if (right != nullptr)
    {
        right->printTreePrefixe();  // afficher le noeud a droite
    }
}



//---------> Parcours en largeur 
void Tree::BFS() const
{
    // si l'arbre est vide
    if (this == nullptr) 
    {
        return;
    }

    // Cr�er une file pour stocker les noeuds � visiter
    queue<Tree*> q;
    q.push(const_cast<Tree*>(this));  // Ajouter la racine � la file

    //et tant que la file n'est pas vide
    while (!q.empty()) 
    {
        // Extraire un noeud de la file
        Tree* current = q.front();
        q.pop();

        // Afficher la valeur du n�ud actuel
        cout << current->donnee << " ";

        // Ajouter les enfants du noeud actuel � la file
        if (current->left != nullptr) 
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}


//---------> chercher une valeur dans l'arbre
bool Tree::chercherVal(int val)
{
    // Si la valeur recherch�e est �gale � la donn�e du n�ud actuel
    if (val == donnee) 
    {
        return true; // La valeur a �t� trouv�e
    }
    // Si la valeur n'est pas trouv�e ici, chercher dans les fils
    bool touveAgauche = false;
    bool touveAdroite = false;

    if (left != nullptr) 
    {
        touveAgauche = left->chercherVal(val); // Recherche dans le sous-arbre gauche
    }

    if (right != nullptr) {
        touveAdroite = right->chercherVal(val); // Recherche dans le sous-arbre droit
    }

    // Retourner true si la valeur a �t� trouv�e dans l'un des sous-arbres
    return touveAdroite || touveAgauche;
}


//----------> destructeur
Tree::~Tree()
{
    delete this->left;
    delete this->right;
}
