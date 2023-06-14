/*!
\file cartes.h
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier en-tete du module cartes permet de gerer les cartes
*/
#ifndef __CARTES_H__
#define __CARTES_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
\enum eCouleur
\brief enumeration des couleurs des cartes
*/
enum eCouleur{
    Pique,treffle,Carreau,Coeur
};
typedef enum eCouleur eCouleur;

/*
\struct sCarte
\brief structure d'une carte
*/
struct sCarte {
    eCouleur couleur;
    int int_valeur;
};
typedef struct sCarte sCarte;


/*
\fn char parseValeur(int int_val)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief convertit une valeur numerique en valeur char
\param int_val valeur numerique
\return valeur char
*/
char parseValeur(int int_val);

/*
\fn void afficherCarte(sCarte carte)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief affiche une carte
\param carte carte a afficher

*/
void afficherCarte(sCarte carte);

/*
\fn sCarte* initJeu()
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief initialise un jeu de 52 cartes
\return pointeur sur le jeu de cartes
*/
sCarte* initJeu();


/*
\fn void melangerJeu(sCarte* jeu)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief melange un jeu de cartes
\param jeu pointeur sur le jeu de cartes
*/
void melangerJeu(sCarte* jeu);


/*
\fn sCarte tirerCarte(sCarte* paquet)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief tire une carte du paquet
\param paquet pointeur sur le paquet de cartes
\return carte tiree
*/
sCarte tirerCarte(sCarte*paquet);

#endif