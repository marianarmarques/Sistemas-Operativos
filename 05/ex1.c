#include <unistd.h>

int main(int argc, char * argv) {

    // pipe_fd[0] = fd de leitura
    // pipe_fd[1] = fd de escrita
    int pipe_fd[2];
    pipe(pipe_fd);

    char buf[20];

    if(fork()==0) {
        close(pipe_fd[1]);

        char buf[10];
        int read_bytes = read(pipe_fd[0], buf, 10);

        _exit(0);
    }

    
    close(pipe_fd[0]);
    write(pipe_fd[1], "data\n", 5);
}