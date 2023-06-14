/*!
\file blackJack.h
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier d'entete du module blackJack
*/
#ifndef __BLACKJACK_H_
#define __BLACKJACK_H_
#include "cartes.h"
#include "joueur.h"
#include "saisie.h"

/*!
\fn deroulementPartie(sJoueur* joueur, sBanque banque, sCarte* paquet, int nbJoueurs)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief procedure qui gere le deroulement de la partie
\param joueur pointeur sur le tableau de joueur
\param banque banque de la partie
\param paquet pointeur sur un tableau de carte
\param nbJoueurs nombre de joueurs

*/
void deroulementPartie(sJoueur* joueur, sBanque banque, sCarte* paquet, int nbJoueurs);


/*!
\fn void FaireJouerJoueur(sJoueur *joueur,sCarte* paquet)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief procedure qui gere le deroulement du tour d'un joueur
\param joueur pointeur sur le joueur
\param paquet pointeur sur un tableau de carte

*/
void FaireJouerJoueur(sJoueur *joueur,sCarte* paquet);

/*!
\fn void verifierScore(sJoueur *joueur, sBanque banque)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief procedure qui verifie le score du joueur et de la banque
\param joueur pointeur sur le joueur
\param banque banque de la partie
*/
void verifierScore(sJoueur *joueur, sBanque banque);

#endif