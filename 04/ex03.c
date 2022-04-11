#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int status;
    int ifd = open("/etc/passwd", O_RDONLY);
    int ofd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int efd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);

    dup2(ifd, 0);
    close(ifd);

    int original_stdout_fd = dup(1);
    dup2(ofd, 1);
    close(ofd);

    dup2(efd, 2);
    close(efd);

    if(fork()==0) {
        //O exec herda os fd do processo pai -> Output em saida.txt
        execlp("wc", "wc", NULL);
        
        _exit(1); 
    }
}