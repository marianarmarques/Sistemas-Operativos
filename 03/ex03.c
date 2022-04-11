#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int i, status;

    for(i=1; i<argc; i++) {
        if(fork()==0) {
             if (execlp(argv[i], argv[i], NULL)<0) perror("execl");
        }
    }

    while(wait(&status)!= -1) {
        printf("%d\n", WEXITSTATUS(status));
    }

    return 0;
}