#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


void ex5(int counter){
    if (counter < 10) {
        pid_t pid = fork();
        if(!pid) ex5(counter+1);
        else{
            //wait(&pid) pela ordem 1,2,3,...
            printf("Meu pid: %d, sou filho de %d, filho: %d\n", getpid(), getppid(), counter+1);
            wait(&pid);
            exit(0);
        }
    }
}

void ex5V2(){
    int i;
    for(i = 1; i <= 10; i++){
        if(i == 10) break;
        pid_t p = fork();
        if(p){
            wait(0);
            break;
        }
    }
    printf("%d %d %d\n", i, getpid(), getppid());
}

