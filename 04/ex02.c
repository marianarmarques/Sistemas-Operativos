#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int ifd = open("/etc/passwd", O_RDONLY);
    int ofd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int efd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);

    int original_stdin_fd = dup(0);
    dup2(ifd, 0);
    close(ifd);

    int original_stdout_fd = dup(1);
    dup2(ofd, 1);
    close(ofd);

    dup2(efd, 2);
    close(efd);

    if(fork()==0) {
        char buf[50];

        int bytes_read = read(0, buf, 50);
        write(1, buf, bytes_read);
        write(2, buf, bytes_read);
        
        _exit(0);
    }

    return 0;
}
