/*!
\file saisie.c
\brief Module de saisie des données
\author Jacques
\version 0.1
*/
#include "saisie.h"


void viderBuffer(){
    
    int c = 0;
    // On vide le buffer
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int saisieEntier()
{
    // Declaration des variables
    int int_entier;
    int int_retour;
    // On demande a l'utilisateur de saisir un entier
    int_retour = scanf("%d", &int_entier);
    // Si l'entrée est correcte on retourne l'entier
    if (int_retour == 1)
    {
        
        return int_entier;
    }
    else
    {
        //sinon on retourne ERREUR_SAISIE
        return ERREUR_SAISIE;
    }
}

int demanderEntier(char *pchar_message){
    // Declaration des variables
    int int_entier;
    // On affiche le message
    printf("%s", pchar_message);
    //Appel de la fonction saisieEntier
    int_entier = saisieEntier();
    //Tant qu'on a une erreur de saisie on redemande a l'utilisateur de saisir un entier
    while(int_entier == ERREUR_SAISIE){
        //Message d'erreur
        printf("Erreur de saisie, veuillez recommencer : ");
        //On vide le buffer
        viderBuffer();
        //On demande a l'utilisateur de saisir un entier
        int_entier = saisieEntier();
    }
    //On retourne l'entier Valide
    return int_entier;
}