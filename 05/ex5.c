#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


/*grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l.*/

int main(int argc, char * argv[]) {

    // pipe[0] = fd de leitura
    // pipe[1] = fd de escrita
    int fd_pipe[3][2];
    
    if(pipe(fd_pipe[0])<0) perror("pipe1");

    if(fork()==0) {
        close(fd_pipe[0][0]);

        dup2(fd_pipe[0][1], 1);
        close(fd_pipe[0][1]);

        execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
        _exit(1);
    }
    close(fd_pipe[0][1]);

    if(pipe(fd_pipe[1])<0) perror("pipe2");

    if(fork()==0) {
        close(fd_pipe[1][0]);

        dup2(fd_pipe[0][0], 0); // redirecionar a saída do programa para a entrada do pipe seguinte
        close(fd_pipe[0][0]);

        dup2(fd_pipe[1][1],1);
        close(fd_pipe[1][1]);

        execlp("cut", "cut", "-f7", "-d:", NULL);
        _exit(1);
    }
    close(fd_pipe[0][0]);
    close(fd_pipe[1][1]);

    if(pipe(fd_pipe[2])<0) perror("pipe3");

    if(fork()==0) {
        close(fd_pipe[2][0]);

        dup2(fd_pipe[1][0],0); // redirecionar a saída do programa para a entrada do pipe seguinte
        close(fd_pipe[1][0]);

        dup2(fd_pipe[2][1], 1);
        close(fd_pipe[2][1]);


        execlp("uniq", "uniq", NULL);
        _exit(1);
    }
    close(fd_pipe[1][0]);
    close(fd_pipe[2][1]);

    if(fork()==0) {
        dup2(fd_pipe[2][0], 0); // redirecionar a saída do programa para a entrada do pipe seguinte
        close(fd_pipe[2][0]);

        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }
    close(fd_pipe[2][0]);

    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}