#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
O segundo repete para este pipe todas as linhas de texto lidas a partir do seu standard input.
*/

int main(int argc, int argv[]) {
    int bytes_read;
    char buf[1024];

    int fd1 = open("fifo", O_WRONLY);

    while((bytes_read=read(0, buf, 1024))>0) {
        write(fd1, buf, bytes_read);
    }

    close(fd1);
    
    return 0;
}