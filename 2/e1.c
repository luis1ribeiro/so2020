#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  pid_t pid;

  if ((pid = fork())==0) {
      printf("Sou o filho e tenho o pid: %d\nO meu pai tem pid: %d\n\n", getpid(),getppid());
  }
  else {
      printf("Sou o pai e tenho o pid: %d\nO meu filho tem pid: %d\n\n", getpid(),pid);
  }
  return 0;

}
