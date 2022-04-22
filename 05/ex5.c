#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

    // pipe[0] = fd de leitura
    // pipe[1] = fd de escrita
    int pipe1[2];
    if(pipe(pipe1)<0) perror("pipe1");

    if(fork()==0) {
        close(pipe1[0]);

        dup2(pipe1[1], 1);
        close(pipe1[1]);

        execlp("grep", "grep", "-v", "^#", NULL);
    }


    return 0;
}