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
  if ((key = ftok("mem.c",'R')) == -1){
      perror("ftok");
      exit(1);
  }

  if((schmid = shmget(key,SHM_SIZE,0644 | IPC_CREAT)) == -1){
    perror("schmget");
    exit(1);
  }

  shared = shmat(shmid,(void *)0,0);
  if(shared == (char *) -1){
    perror("schmat");
    exit(1);
  }
  
  printf("This is the shared memory %s \n",shared);
  printf("Do you want to change the data?(Y or N) ");
  char command[200];
  fgets(command,1,stdin);
  if(!strcmp(command[0],"Y")){
      printf("Enter your change: ");
      fgets(command,200,stdin);
      
  }
  
}
  
 
  
