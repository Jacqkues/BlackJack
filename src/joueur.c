/*
\file joueur.c
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier d'implementation du module joueur
*/

#include "joueur.h"

int convertScore(int int_val, int int_score)
{
    //on verifie la valeur de la carte
    //si elle est supérieur à 10 c'est une figure qui vaut 10
    if (int_val > 10)
    {
        //on retourn donc 10
        return 10;
    }
    //si c'est un as
    else if (int_val == 1)
    {
        //on verifie si le score est supérieur à 21
        if (int_score + 11 > 21)
        {   
            //si c'est le cas on retourne 1 pour valeur de l'as pour ne pas depasser 21
            return 1;
        }
        else
        {
            //sinon on retourne 11 pour valeur de l'as
            return 11;
        }
    }
    //sinon on retourne la valeur de la carte
    return int_val;
}

sJoueur initJoueur(sCarte *paquet)
{
    //decalaration d'une variable joueur
    sJoueur joueur;
    //on initialise les valeurs de la variable joueur
    //initialisation du bankroll à 100
    joueur.bankroll = 100;
    //initialisation du nombre de carte à 1
    joueur.nbCartes = 1;
    //initialisation de la mise à 0
    joueur.mise = 0;

    //initialisation du score à 0
    joueur.score = 0;

    //on demande le nom du joueur
    int int_nom_retour;
    printf("entrer votre nom : ");
    //on lit le nom du joueur
    int_nom_retour = scanf("%s", joueur.nom);
    //on verifie si le nom a été bien lu
    if (int_nom_retour == 0)
    {
        //si le nom n'a pas été bien lu
        //on affiche un message d'erreur
        printf("erreur de saisie\n");
        //on quitte le programme
        exit(1);
    }

    //on tire la première carte du joueur
    joueur.main[0] = tirerCarte(paquet);
    //on tire la deuxième carte du joueur
    joueur.main[1] = tirerCarte(paquet);
    //on calcule le score du joueur
    joueur.score = convertScore(joueur.main[0].int_valeur, joueur.score) + convertScore(joueur.main[1].int_valeur, joueur.score);
    //on retourne le joueur
    return joueur;
}

sBanque initBanque(sCarte *paquet)
{
    //on decalre une variable banque
    sBanque banque;
    //on initialise le nombre de carte à 0
    banque.nbCartes = 0;
    //on initialise le score à 0
    banque.score = 0;
    //tant que le score de la banque est inférieur à 17
    while (banque.score < 17)
    {
        //on tire une carte
        banque.main[banque.nbCartes] = tirerCarte(paquet);
        //on calcule le score de la banque
        banque.score += convertScore(banque.main[banque.nbCartes].int_valeur, banque.score);
        //on incremente le nombre de carte de la banque
        banque.nbCartes++;
    }
    //on retourne la banque
    return banque;
}

void afficherCarteJoueur(sJoueur joueur)
{
    //on affiche la main du joueur
    printf("\tmain de %s : \n", joueur.nom);
    for (int i = 0; i < joueur.nbCartes + 1; i++)
    {
        printf("\t");
        afficherCarte(joueur.main[i]);
    }
}
void faireMise(sJoueur *joueur)
{
    //on verifie si le joueur a encore de l'argent
    if(joueur->bankroll == 0){
        //si le joueur n'a plus d'argent
        //on affiche un message
        printf("%s vous ne pouvez plus jouer car vous etes ruiner\n",joueur->nom);
        //on quitte le programme
        exit(0);
    }
    //sinon on fait la mise
    int int_mise;
    printf("\nC'est à %s de miser : \n", joueur->nom);
    printf("votre bankroll est de %d\n", joueur->bankroll);
    //on demande au joueur de faire sa mise
    int_mise = demanderEntier("combien voulez vous miser ? : ");
    //on verifie si la mise est supérieur à la bankroll du joueur
    if (int_mise > joueur->bankroll)
    {
        //si c'est le cas on affiche un message d'erreur
        printf("vous ne pouvez pas miser plus que votre bankroll !\n");
        //on relance la fonction
        faireMise(joueur);
    }
    else
    {
        //sinon on met à jour la mise du joueur
        joueur->mise = int_mise;
        //on met à jour la bankroll du joueur
        joueur->bankroll -= int_mise;
    }
}