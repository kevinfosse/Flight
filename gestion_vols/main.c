#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h" 



int main(int argc, char *argv[]) {
int opt; 
char *ptr;
int Nom, Compagnie, Duree; // on déclare les variables en int

	if (argc > 1)
	{
		
		if ((opt = getopt(argc, argv, "h")) != -1) // Si l'argument h est présent alors il print l'exemple d'utilisation
				{
				
					
						 printf("Exemple d'utilisation \n");
						 printf("%s [Nom] [Compagnie] [Duree] \n", argv[0]);
						 printf("Veuillez utiliser les chiffres\n\n");
					
				}
					else { 				//Sinon il execute le programme

		// je change le type de char vers int grace à strtol 
		// je recois une erreur si je cast le type en haut 

		if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL) {
			 Nom = strtol(argv[1], &ptr, 10);
		 	 Compagnie = strtol(argv[2], &ptr, 10);
		 	 Duree = atoi(argv[3]);
		}

		
					

					//printf("Nom de l'avion %d", Nom);
					//printf("Compagnie : %d", Compagnie);
					//printf("Duree : %d", Duree);	

					detect_args(Nom,Compagnie,Duree);

						return 0; 
						 
					}

				}	

	
	else { // si argc 0 alors printf 
	display();
	//printf("Utilisez l'argument -h pour avoir une aide \n");
		}
	
}
