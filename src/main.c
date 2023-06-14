/*
\file main.c
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier main du jeu de black jack
*/

#include <stdio.h>
#include "cartes.h"
#include "joueur.h"
#include <time.h>
#include "blackJack.h"
int main(int argc, char *argv[])
{
    //on verifie si le nombre d'argument est correct
    if(argc != 2)
    {
        //si ce n'est pas le cas on affiche un message d'erreur
        printf("erreur de saisie\n");
        printf("usage : ./blackJack nombre_de_joueur\n");
        exit(1);
    }
    //on recupere le nombre de joueur depuis les arguments
    int int_nb_joueur = atoi(argv[1]);

    //on verifie si le nombre de joueur est correct
    if (int_nb_joueur < 1 || int_nb_joueur > 5)
    {
        printf("erreur de saisie\n");
        exit(1);
    }

    //on initialise le generateur de nombre aleatoire
    srand(time(NULL));
    //on initialise le jeu de carte
    sCarte *jeu = initJeu();
    //on melange le jeu de carte
    melangerJeu(jeu);
    

    // pour chaque joueur, initialiser le joueur
    sJoueur *joueurs = malloc(sizeof(sJoueur) * int_nb_joueur);
    for (int i = 0; i < int_nb_joueur; i++)
    {
        joueurs[i] = initJoueur(jeu);
        printf("\n");
    }

    // initialiser la banque
    sBanque banque = initBanque(jeu);

    // lancer le jeu
    deroulementPartie(joueurs, banque, jeu, int_nb_joueur);

    return 0;
}