#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv) {

    // pipe_fd[0] = fd de leitura
    // pipe_fd[1] = fd de escrita
    int pipe_fd[2];
    pipe(pipe_fd);

    char buf[1024];


    if(fork()==0) {
        close(pipe_fd[1]);

        //Redirecionar o input do programa para a saída do pipe, onde ocorre a leitura dos dados.
        dup2(pipe_fd[0], 0);
        //Tanto o fd pipe_fd e 0 estão a apontar para o mesmo recurso, pode dar erro.
        close(pipe_fd[0]);

        execlp("wc", "wc", NULL);

        _exit(1);
    }

    close(pipe_fd[0]);

    int read_bytes;
    while((read_bytes = read(0, buf, 1024))>0) write(pipe_fd[1], buf, read_bytes);
    
    close(pipe_fd[1]); //Garantir EOF
}