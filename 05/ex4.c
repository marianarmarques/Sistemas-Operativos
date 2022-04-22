#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

    // pipe_fd[0] = fd de leitura
    // pipe_fd[1] = fd de escrita
    int pipe_fd[2];

    if(pipe(pipe_fd)<0) perror("pipe");

    if(fork()==0) {
        close(pipe_fd[0]);

        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);

        if(execlp("ls", "ls", "/etc", NULL)<0);
        _exit(1);
    }

    close(pipe_fd[1]);

    if(fork()==0) {

        dup2(pipe_fd[0], 0);
        close(pipe_fd[0]);

        if(execlp("wc", "wc", "-l", NULL)<0);
        _exit(1);

    }

    close(pipe_fd[0]);

    wait(NULL);
    wait(NULL);

    return 0;
}