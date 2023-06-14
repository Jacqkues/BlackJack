/*
\file joueur.h
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier d'entete du module joueur
*/

#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include "cartes.h"
#include "saisie.h"

/*
\struct joueur
\brief structure d'un joueur
*/
struct joueur
{
    char nom[20];
    int bankroll;
    int mise;
    int nbCartes;
    int score;
    sCarte main[10];
};
typedef struct joueur sJoueur;

/*
\struct banque
\brief structure de la banque
*/
struct  banque
{
   int nbCartes;
   int score;
   sCarte main[10];
};
typedef struct banque sBanque;


/*
\fn sJoueur initJoueur()
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief initialise un joueur
\return joueur initialise
*/
sJoueur initJoueur();

/*
\fn sBanque initBanque()
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief initialise la banque
\return banque initialise
*/
sBanque initBanque();

/*
\fn void afficherCarteJoueur(sJoueur joueur)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief affiche les cartes du joueur
\param joueur joueur dont on veut afficher les cartes

*/
void afficherCarteJoueur(sJoueur joueur);

/*
\int convertScore(int int_val, int int_score)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief convertit la valeur d'une carte en score
\param int_val valeur de la carte
\param int_score score du joueur
\return score réel de la carte
*/
int convertScore(int int_val, int int_score);

/*
\fn void faireMise(sJoueur *joueur)
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fait une mise
\param joueur joueur qui fait la mise
*/
void faireMise(sJoueur *joueur);

#endif