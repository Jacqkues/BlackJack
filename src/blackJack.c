/*!
\file blackJack.c
\author Jacques
\date 27 decembre 2022
\version 0.1
\brief fichier source du module blackJack
*/
#include "blackJack.h"

void verifierScore(sJoueur *joueur, sBanque banque)
{
    // si la banque a plus de 21 et que le joueur a misé et n'a pas perdu
    if (banque.score > 21 && joueur->mise != 0)
    {
        // alors il gagne le montant de sa mise
        printf("\t\t%s vous avez gagné %d\n", joueur->nom, joueur->mise * 2);
        joueur->bankroll += joueur->mise * 2;
        joueur->mise = 0;
    }
    // si le joueur a plus que la banque sans depasser 21 et qu'il a misé
    else if (joueur->mise != 0 && joueur->score > banque.score && joueur->score <= 21)
    {
        // alors il gagne le montant de sa mise
        printf("\t\t%s vous avez gagné %d\n", joueur->nom, joueur->mise * 2);
        joueur->bankroll += joueur->mise * 2;
        joueur->mise = 0;
    }
    // si le joueur a fait égalité avec la banque et qu'il a misé8
    else if (joueur->mise != 0 && joueur->score == banque.score)
    {
        // si le joueur a fait un blackjack et que la banque n'a pas fait de blackjack (plus de 2 cartes pour faire 21)
        if (joueur->score == 21 && joueur->nbCartes == 2 && banque.nbCartes != 2)
        {
            // alors il le double de sa mise
            printf("\t\t%s vous avez gagné %d\n", joueur->nom, joueur->mise * 3);
            joueur->bankroll += joueur->mise * 3;
            joueur->mise = 0;
        }
        // sinon il a fait égalité et il recupere sa mise
        printf("\t\t%s vous avez fait égalité%d\n", joueur->nom, joueur->mise);
        joueur->bankroll += joueur->mise;
        joueur->mise = 0;
    }
    // si le joueur a perdu car il a moins que la banque et qu'il a misé
    else if (joueur->mise != 0 && joueur->score < banque.score)
    {
        // alors il perd sa mise
        printf("\t\t%s vous avez perdu %d\n", joueur->nom, joueur->mise);
        joueur->mise = 0;
    }
    // si le joueur fait 21 en deux cartes (blackjack)
    else if (joueur->mise != 0 && joueur->nbCartes == 2 && joueur->score == 21)
    {
        // alors il gagnge le double de sa mise
        printf("\t\t%s vous avez gagné %d\n", joueur->nom, joueur->mise * 3);
        joueur->bankroll += joueur->mise * 3;
        joueur->mise = 0;
    }
    // si le joueur a perdu car il a plus de 21
    else if (joueur->score > 21)
    {
        // alors il perd sa mise
        printf("\t\t%s vous avez perdu\n", joueur->nom);
        joueur->mise = 0;
    }
}

void deroulementPartie(sJoueur *joueur, sBanque banque, sCarte *paquet, int nbJoueurs)
{
    // on fait miser chaque joueur
    for (int i = 0; i < nbJoueurs; i++)
    {
        faireMise(&joueur[i]);
    }

    // afficher une carte  de la banque
    printf("\t\t Cartes de la banque : \n\t\t\t");
    afficherCarte(banque.main[0]);
    printf("\n");
    // afficher carte joueur
    for (int i = 0; i < nbJoueurs; i++)
    {
        afficherCarteJoueur(joueur[i]);
        printf("\n");
    }
    // on fait jouer chaque joueur
    for (int i = 0; i < nbJoueurs; i++)
    {
        FaireJouerJoueur(&joueur[i], paquet);
    }
    // afficher toute les cartes de la banque :
    printf("\t\tMain de la banque : \n\t\t\t");

    for (int i = 0; i < banque.nbCartes; i++)
    {
        afficherCarte(banque.main[i]);
    }
    // pour chaque joueur on verifie le score
    printf("\n\tRésultat de la partie : \n");
    for (int i = 0; i < nbJoueurs; i++)
    {
        verifierScore(&joueur[i], banque);
    }
    // on demande à l'utilisateur si il veut rejouer
    printf("Voulez vous rejouer ?\n");
    int int_rejouer;
    // pour ça il choisit 1 pour oui et 0 pour non
    int_rejouer = demanderEntier("1 pour oui , 0 pour non : ");
    // si il veut rejouer
    if (int_rejouer == 1)
    {
        // initialisation du jeu
        sCarte *jeu = initJeu();
        // mélange du jeu de carte
        melangerJeu(jeu);
        // on reinitialise les cartes des joueurs
        for (int i = 0; i < nbJoueurs; i++)
        {
            // declaration d'une carte vide
            sCarte carte_vide;
            carte_vide.couleur = -1;
            carte_vide.int_valeur = -1;
            // on remplace les cartes des joueurs par des cartes vides
            for (int j = 0; j < joueur[i].nbCartes; j++)
            {
                joueur[i].main[j] = carte_vide;
            }

            // on met le score à 0

            joueur[i].score = 0;
            // on met le nombre de carte à 2 cartes (donc a 1 car on commence à 0)
            joueur[i].nbCartes = 1;
            // on tire deux cartes
            joueur[i].main[0] = tirerCarte(jeu);
            joueur[i].main[1] = tirerCarte(jeu);
            // on convertit les cartes en score
            joueur[i].score = convertScore(joueur[i].main[0].int_valeur, joueur[i].score) + convertScore(joueur[i].main[1].int_valeur, joueur[i].score);
        }
        // initialisation de la banque
        sBanque banque = initBanque(jeu);
        // on relance le deroulement de la partie
        deroulementPartie(joueur, banque, jeu, nbJoueurs);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }

    printf("\n");
}

void FaireJouerJoueur(sJoueur *joueur, sCarte *paquet)
{

    int int_choix;
    // on demande au joueur ce qu'il veut faire
    printf("%s que voulez vous faire :\n", joueur->nom);
    // il peut piocher une carte , passer ou calculer son score
    // on demande à l'utilisateur de choisir
    // tant qu'il ne choisit pas 1 , 2 ou 3 on lui redemande
    do
    {
        int_choix = demanderEntier("1: piochez une autre carte , 2: passer , 3: calculer votre score ? :");

    } while (int_choix != 1 && int_choix != 2 && int_choix != 3);
    //si il choisi de piocher une carte ( 1 )
    if (int_choix == 1)
    {
        // on ajoute une carte à sa main
        // on augmente le nombre de carte de 1
        joueur->nbCartes++;
        // on tire une carte qu'on ajoute à sa main
        joueur->main[joueur->nbCartes] = tirerCarte(paquet);
        // on convertit la carte en score et on l'ajoute au score du joueurs
        joueur->score += convertScore(joueur->main[joueur->nbCartes].int_valeur, joueur->score);
        //on lui affiche ses cartes
        printf("Vos cartes sont maintenant : \n");
        afficherCarteJoueur(*joueur);
        printf("\n");
        //si le score est supérieur à 21

        if (joueur->score > 21)
        {
            // on met sa mise à 0
            joueur->mise = 0;
        }
        else
        {
            // sinon on lui redemande ce qu'il veut faire
            FaireJouerJoueur(joueur, paquet);
        }
    }
    //si il choisi de calculer son score ( 3 )
    else if (int_choix == 3)
    {
        //alors on lui affiche son score
        printf("\tVotre score est de %d , attention à ne pas depasser 21 !\n", joueur->score);
        // on lui redemande ce qu'il veut faire
        FaireJouerJoueur(joueur, paquet);
       
    }
     //si il choisi de passer ( 2 )
    else if(int_choix ==2){
        //on lui dit merci et on fait rien d'autre donc on va passer à un autre joueur
        printf("Merci\n");
    }
}