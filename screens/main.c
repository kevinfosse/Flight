#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MAX_CHARAC 25

int main() {


    char Nom[6][25];
    char Compagnie[6][25];
	char transfer[30];
	char clean[6][25];

	int Colonneint;
	int coutdown = 10;
	int intervol = 3;
	
	

	int i, k, j, l;

	int compteur, nbAvionDecollage;

	


  //Nom[0] = p_shm+5;
  //printf("%s \n", Nom[0]); // Nom avion
  //Compagnie[0] = p_shm+25;	
  //printf("%s \n", Compagnie[0]); // Nom compagnie
  //Duree[0] = p_shm+50;
 // printf("%s \n", Duree[0]); // Duree
//printf("%s", p_shm);

	key_t cle;
	int shmid;
	char *p_shm;
	cle = ftok("../key.bin", 1);
	shmid = shmget(cle,50,IPC_CREAT | 0640);
	p_shm = (char *)shmat(shmid, 0, 0);
  	
	  system("clear");

do
{
		
//sleep(1);
	
	//	int bool = atoi(p_shm);
		int verif = atoi(p_shm+2);
	//	if (bool == 0) {

	//		Nom[0] = p_shm+5;
	//		Compagnie[0] = p_shm+25;

	//		sprintf(p_shm, "1");
	//	}



		


	if(verif != 0) { // permet de vérifier si une saisie à été entrer
	// i = i + 1;
	// if(i > 5) { 
	
	//	i = 1;
	//	sleep(2);
	//	system("clear");
// }

		if(Colonneint > 4) {
			Colonneint = 0;
			memset(Nom, 0, sizeof Nom);
		}

		if(Colonneint > 4) {
			Colonneint = 0;
			memset(Compagnie, 0, sizeof Compagnie);


		}

		if(coutdown == 0) {
			coutdown = 10;
		}

		// Insertion des noms dans tableau 2D

		// Nom[k][j]
		

	sprintf(transfer, p_shm+15); // transfer = nom
	

	if(Colonneint < 5) { // le parent // pour le nom
		for(j = 0; j < MAX_CHARAC; j++) { // le contenu
			if(transfer[j] != '\0' | transfer[j] != '@' ) {
				Nom[Colonneint][j] = transfer[j];
			}
			else {

				break;

			}
		}
	}
	
		strcpy(transfer, p_shm+40); // tranfert = compagnies


	if(Colonneint < 5) { // le parent // pour la compagnie
		for(j = 0; j < MAX_CHARAC; j++) { // le contenu
			if(transfer[j] != '\0' | transfer[j] != '@' ) {
				Compagnie[Colonneint][j] = transfer[j];
			}
			else {

				break;
			}
		}
	}



				Colonneint++;
				l++;
				nbAvionDecollage = 0;

	for (compteur = 1; compteur < 5; compteur++)
{
		if(Nom[compteur][0] && Compagnie[compteur][0] != '@') {
		if(Nom[compteur][0] && Compagnie[compteur][0] != '\0') {

				nbAvionDecollage++;

			}
		}	
	}


	sprintf(p_shm+2, "0");




}

// Affichage 



if(Nom[0][0] && Compagnie[0][0] != '@') {

printf("Décollage en cours oui | Prochain décollage : ");
printf("%s %s \n", Nom[0], Compagnie[0]);

if(coutdown > 0) {
coutdown--;
}

else if(coutdown == 0) {
	memset(Nom[0], '\0', sizeof(Nom[0]));
}
printf("Durée de décollage restant : %d \n", coutdown);


}
else {
	printf("Décollage en cours non | Prochain décollage :\n");
	printf("Durée de décollage restant : \n");
	printf("Durée intervolle %d", intervol);

	if(coutdown == 0 && intervol > 0) {
		intervol--;
	}

	else if(coutdown == 0 && intervol == 0) {
		coutdown = 10;
		intervol = 3;
		int change;


		for(change = 5; change > 0; change--) { // le parent // pour la compagnie
		for(j = 0; j < MAX_CHARAC; j++) { // le contenu
			if(Nom[change] != '\0' | Nom[change] != '@' ) {

				Nom[change-1][j] = Nom[change][j];

			}
			else {
				change--;
				break;
			}
		}
	}


	}

}




printf("Nombre d'avion en attente : %d \n", nbAvionDecollage);

// Tableau 



for(i = 1; i < 5; i++) {
		if(Nom[i][0] && Compagnie[i][0] != '\0') {
	printf("%d. %s %s \n", i, Nom[i], Compagnie[i]);
		}
		else { break;}
	}
		printf("\n");
		sleep(1);
		system("clear");

 }while(1);


}

