#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

int main (int argc, char* argv[]) {
	int fd; int logs; int bytes_read;
	char buf [MAX_LINE_SIZE];

	//unlink("~/uni/so/2020/6/pip");

	if (mkfifo("pip", 0666) == -1) {
		perror("mkfifo");
  }


	logs = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (logs < 0) {
	  perror("log fak");
  }

  while(1) { //se abrir o decritor de escrita do pipe não preciso deste loop
    	if ((fd = open("pip", O_RDONLY)) == -1) {
		      perror ("open");
		      return -1;
	    } else {
          printf("[SERVER]: Opened pipe for reading\n");
	    }

    while((bytes_read = read(fd, &buf, MAX_LINE_SIZE))>0) {
		  write(logs, &buf, bytes_read);
	  }
	}

	//unlink("~/uni/so/2020/6/pip");


  return 0;
}




