#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "header.h" 



void transfer(char *Nom, char *Compagnie) {

    key_t key;
    int shmid;
    char *p_shm;


    key = ftok("../key.bin", 1);


    // Nom
    shmid = shmget(key,50,IPC_CREAT | 0640);
    p_shm = (char *)shmat(shmid, 0, 0);
    sprintf(p_shm, "0");

	sprintf(p_shm+5, Nom);
    p_shm = p_shm+25;
    sprintf(p_shm, Compagnie);


	shmdt(p_shm);

}