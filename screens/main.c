#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "../gestion_vols/header.h"

int main() {


    char *Nom[10];
    char *Compagnie[10];
	char *Duree[10];

	int i;

	


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
	
		int bool = atoi(p_shm);

		if (bool == 0) {

			Nom[0] = p_shm+5;
			Compagnie[0] = p_shm+25;

			sprintf(p_shm, "1");
		}


	i = i + 1;
	if(i > 5) { 
	
		i = 1;
		sleep(2);
		system("clear");
}

	printf("%d. %s %s \n", i, Nom[0],Compagnie[0]);



			}


	

  




}

