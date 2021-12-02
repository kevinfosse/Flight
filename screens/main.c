#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "../gestion_vols/ecran.h"

int main() {

	key_t cle;
	int shmid;
	char *p_shm;
	cle = ftok("../key.bin", 1);
	shmid = shmget(cle,50,IPC_CREAT | 0640);
	p_shm = (char *)shmat(shmid, 0, 0);
    char *Nom[10];
    char *Compagnie[10];
	int test;

	for (test = 0; test < 10; test++)
	{


	}
	


    
  printf("%s \n", p_shm);	

  
  return 0;




}

