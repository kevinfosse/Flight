// Ce programme permet de réattribuer les compagnies et les noms en fonction du chiffre entrée

#include <stdio.h>
#include <stdlib.h>
#include "detect_args.h"
#include <string.h>
#include "ecran.h"


void detect_args(int cNom, int cCompagnie, int cDuree) {

    if(cNom == 0 | cCompagnie == 0 | cDuree == 0) // Sécurités
    {   
        system("clear");
        printf("\n\n");
        printf("Erreur veuillez réessayer \n");
        printf("Vous pouvez consulter l'aide avec -h\n\n");
    }

    else {

    

    char *Nom, *Compagnie;

    switch (cNom) // Attribution du texte par rapport au choix pour le nom
    {
    case 1:
        Nom = "Airbus 420";
        break;
    case 2: 
        Nom = "Boeing 747";
        break;
    case 3:
        Nom = "Fokker";
        break;
    case 4: 
        Nom = "Embraer Brasilia";
        break;
    case 5:
        Nom = "Jet Stream";
        break;
    
    default:
        break;
    }
            //////////////////////////////////////////////////////////////////////////::


    switch (cCompagnie) // Attribution du texte par rapport au choix pour le nom
    {
    case 1:
        Compagnie = "Air France";
        break;
    case 2: 
        Compagnie = "Air Canada";
        break;
    case 3:
        Compagnie = "Easy Jet";
        break;
    case 4: 
        Compagnie = "CorsairFly";
        break;
    case 5:
        Compagnie = "Air Tahiti";
        break;
    
    default:
        break;
    }
    system("clear");   
    f("Ajout de l'entrée utilisateur");
    printf("\n%s / %s / %d \n\n", Nom, Compagnie, cDuree);


    }
}