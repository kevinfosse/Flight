#include <stdio.h>
#include <stdlib.h>
#include "ecran.h" 
#include <string.h>


void f(char *s)
{
  printf("---%*s%*s---\n",36+strlen(s)/2,s,38-strlen(s)/2,"");}

void display(void)
{
    system("clear");
     f("Programme de gestion des vols");
     printf("Les avions repertoriees sont:       Les compagnies repertoriees sont:\n\n");
     printf("1. Airbus 420                       1. Air France\n");
     printf("2. Boeing 747                       2. Air Canada\n");
     printf("3. Fokker                           3. Easy Jet\n");
     printf("4. Embraer Brasilia                 4. CorsairFly\n");
     printf("5. Jet Stream                       5. Air Tahiti\n");
     printf("\n\n");
     f("Utiliser l'argument -h pour plus d'informations");
     printf("\n\n\n");

     



}


