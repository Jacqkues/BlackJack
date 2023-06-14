/*!
\file saisie.h
\brief Fichier d'en-tête de saisie.c , fonction qui permettent de saisir des données
\author Jacques Dumora
\version 0.1
*/

#ifndef __SAISIE_H__
#define __SAISIE_H__


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERREUR_SAISIE -1


/**
 * \fn int saisieEntier()
 * \brief Fonction qui permet de saisir un entier
 * \author Jacques
 * \version 0.1
 * \return l'entier saisie
 */
int saisieEntier();


/**
 * \fn int demanderEntier(char *message)
 * \brief Fonction qui permet de demander un entier
 * \author Jacques
 * \version 0.1
 * \param *message : pointeur sur le message
 * \return l'entier saisie
 */

int demanderEntier(char *pchar_message);

/**
 * \fn void viderBuffer()
 * \brief Procedure qui permet de vider le buffer
 * \author Jacques
 * \version 0.1
 */
void viderBuffer();

#endif