#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "person.h"

int main (int argc, char *argv[]){
  if (argc<4){
    printf("Invalid operation");
    return 0;
  }
  int fd=open("pessoas.txt", O_CREAT | O_TRUNC | O_WRONLY);
  if (strcmp(argv[1],"-i")==0){
    int age = atoi(argv[3]);
    char* name = argv[2];
    Person p = new_person (name,age);
    lseek(fd,0,SEEK_END);
    write(fd,&p,sizeof(struct Person));
    close(fd);
  }
  if (strcmp(argv[1],"-u")==0){
    //apenas atualiza a ultima posicao
    int age = atoi (argv[3]);
    Person p;
    lseek(fd,sizeof(struct Person),SEEK_END);
    read(fd,&p,sizeof(struct Person));
    person_change_age(&p,age);
    lseek(fd,sizeof(struct Person),SEEK_CUR);
    write(fd,&p,sizeof(struct Person));
    close(fd);
  }
  return 0;
}

