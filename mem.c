#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 200

int main(int argc, char * argv[]){
  key_t key ;
  int shmid;
  char * shared;
  char command[200];
  key = ftok("./mem.c",'R');
  shmid = shmget(key,SHM_SIZE,0644 | IPC_CREAT);
  shared = shmat(shmid,(void *)0,0);
  
  printf("This is the shared memory %s \n",shared);
  printf("Do you want to change the data?(y or n):");
  fgets(command,200,stdin);
  printf("\n");
  if(command[0] == 'y'){
    printf("\n Enter your change: ");
    fgets(command,200,stdin);
    command[strlen(command) - 1] = 0;
    strcpy(shared,command);
  }
  printf("Do you want to delete this shared memory?(y or n)");
  fgets(command,200,stdin);
  printf("\n");
  if(command[0] == 'y'){
    shmdt(shared);
    shmctl(shmid, IPC_RMID,NULL);
  }

  return 0;
  
  }
  
 
  
