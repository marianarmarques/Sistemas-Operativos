#include <unistd.h>
#include <stdio.h>

//EOF é read() retornar 0
int main(int argc, char * argv) {

    // pipe_fd[0] = fd de leitura
    // pipe_fd[1] = fd de escrita
    int pipe_fd[2];
    pipe(pipe_fd);

    if(fork()==0) {
        close(pipe_fd[1]);

        char buf[1024];
        int read_bytes;
        
        while((read_bytes = read(pipe_fd[0], buf, 1024))>0);
        printf("%d \n", read_bytes); //Verificar EOF

        _exit(0);
    }

    close(pipe_fd[0]);
    
    write(pipe_fd[1], "data\n", 5);
    close(pipe_fd[1]); //Garantir EOF
}
