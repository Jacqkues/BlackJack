/*!
\file blackJack.c
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier source du module cartes
*/

#include "cartes.h"

char parseValeur(int int_val)
{
    //on verifie la valeur de la carte
    switch (int_val)
    {
    case 1:
        //si c'est 1 alors c'est un as
        return 'A';
        break;
    case 11:
        //si c'est 11 alors c'est un valet
        return 'J';
        break;
    case 12:
        //si c'est 12 alors c'est une dame
        return 'Q';
        break;
    case 13:
        //si c'est 13 alors c'est un roi
        return 'K';
        break;
    default:
        //sinon on retourne la valeur de la carte
        return int_val;
        break;
    }
}



void afficherCarte(sCarte carte)
{
    //on verifie la couleur de la carte
    switch (carte.couleur)
    {
    case Pique:
        //si c'est un pique
        //on verifie la valeur de la carte
        //si c'est un valet, une dame ou un roi
        if (carte.int_valeur > 10 || carte.int_valeur == 1)
        {
            //on affiche la valeur de la carte aprés l'avoir convertie
            printf("%c\u2660 ", parseValeur(carte.int_valeur));
        }
        else
        {
            //sinon on affiche la valeur de la carte
            printf("%d\u2660 ", carte.int_valeur);
        }
        break;
    case treffle:
        //si c'est un treffle
        //on verifie la valeur de la carte
        //si c'est un valet, une dame ou un roi
        if (carte.int_valeur > 10 || carte.int_valeur == 1)
        {
            //on affiche la valeur de la carte aprés l'avoir convertie
            printf("%c\u2663 ", parseValeur(carte.int_valeur));
        }
        else
        {
            //sinon on affiche la valeur de la carte
            printf("%d\u2663 ", carte.int_valeur);
        }
        break;
    case Carreau:
        //si c'est un carreau
        //on verifie la valeur de la carte
        //si c'est un valet, une dame ou un roi

        printf("\033[0;31m");
        if (carte.int_valeur > 10 || carte.int_valeur == 1)
        {
            //on affiche la valeur de la carte aprés l'avoir convertie
            printf("%c\u2666 ", parseValeur(carte.int_valeur));
        }
        else
        {
            //sinon on affiche la valeur de la carte
            printf("%d\u2666 ", carte.int_valeur);
        }
        printf("\033[0m");

        break;
    case Coeur:
        //si c'est un coeur
        //on verifie la valeur de la carte
        //si c'est un valet, une dame ou un roi

        printf("\033[0;31m");
        if (carte.int_valeur > 10 || carte.int_valeur == 1)
        {
            //on affiche la valeur de la carte aprés l'avoir convertie
            printf("%c\u2665 ", parseValeur(carte.int_valeur));
        }
        else
        {
            //sinon on affiche la valeur de la carte
            printf("%d\u2665 ", carte.int_valeur);
        }
        printf("\033[0m");
        break;

    default:
        break;
    }
}

sCarte *initJeu()
{
    //on alloue la memoire pour le jeu de carte qui est de 52 cartes
    sCarte *jeu = malloc(52 * sizeof(sCarte));
    //on initialise un compteur à zero
    int int_compteur = 0;
    //on parcours les couleurs
    for (int j = 0; j < 4; j++)
    {
        //on parcours les valeurs
        for (int k = 1; k < 14; k++)
        {
            //on initialise la carte avec sa valeur et sa couleur
            jeu[int_compteur].couleur = j;
            jeu[int_compteur].int_valeur = k;
            int_compteur++;
        }
    }
    //on retourne le jeu de carte
    return jeu;
}

void melangerJeu(sCarte *jeu)
{
    //on initialise une carte temporaire
    sCarte temp;
    //on initialise un nombre aleatoire
    int int_rand;

    //on parcours le jeu de carte
    for (int i = 0; i < 52; i++)
    {
        //on melange le jeu de carte
        //on tire un nombre aleatoire entre 0 et 52
        int_rand = rand() % 52;
        //on ajoute 1 au nombre aleatoire 
        //int_rand++;
        //on echange la carte avec la carte aleatoire
        temp = jeu[i];
        jeu[i] = jeu[int_rand];
        jeu[int_rand] = temp;
    }
}

sCarte tirerCarte(sCarte *paquet)
{

    //on tire un nombre aleatoire entre 0 et 51
    int int_rand = rand() % 52;
   
   //on verifie si la carte a deja ete tiree
    if (paquet[int_rand].int_valeur == -1)
    {
       //si la carte a deja ete tiree on en tire une autre nouveau
        return tirerCarte(paquet);
    }
    //sinon on pioche la carte
    sCarte carte = paquet[int_rand];
   //on met la valeur de la carte a -1 pour dire qu'elle a deja ete tiree
    paquet[int_rand].int_valeur = -1;
    return carte;
}