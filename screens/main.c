#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "../gestion_vols/header.h"
#include <string.h>

#define MAX_CHARAC 25

int main() {


    char Nom[6][25];
    char Compagnie[6][25];
	char transfer[30];
	char clean[6][25];
	

	int i, k, j, l;

	


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

	  

  while(1) { 
	//sleep(1);
	
	//	int bool = atoi(p_shm);
		int verif = atoi(p_shm+2);
	//	if (bool == 0) {

	//		Nom[0] = p_shm+5;
	//		Compagnie[0] = p_shm+25;

	//		sprintf(p_shm, "1");
	//	}

	



	if(verif != 0) { // permet de vérifier si une saisie à été entrer
	i = i + 1;
	if(i > 5) { 
	
		i = 1;
		sleep(2);
		system("clear");
}

		if(k > 4) {
			k = 0;
			memset(Nom, 0, sizeof Nom);
		}

		if(l > 4) {
			l = 0;
			memset(Compagnie, 0, sizeof Compagnie);


		}

		// Insertion des noms dans tableau 2D

		// Nom[k][j]
		

	sprintf(transfer, p_shm+15); // transfer = nom
	

	if(k < 5) { // le parent // pour le nom
		for(j = 0; j < MAX_CHARAC; j++) { // le contenu
			if(transfer[j] != '\0' | transfer[j] != '@' ) {
				Nom[k][j] = transfer[j];
			}
			else {

				break;

			}
		}
	}
	
		strcpy(transfer, p_shm+40); // tranfert = compagnies


	if(l < 5) { // le parent // pour la compagnie
		for(j = 0; j < MAX_CHARAC; j++) { // le contenu
			if(transfer[j] != '\0' | transfer[j] != '@' ) {
				Compagnie[l][j] = transfer[j];
			}
			else {

				break;
			}
		}
	}
	
						


//	printf("\n %d. %s %s \n", i, p_shm+5, p_shm+25);
//	printf("\x1b[1F"); // Move to beginning of previous line
//	printf("\x1b[2K"); // Clear entire line

				k++;
				l++;

	sprintf(p_shm+2, "0");


	}



			}


	

  




}

