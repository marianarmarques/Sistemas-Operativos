#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
Por sua vez, o terceiro programa repete para o seu standard output todas as linhas de texto lidas a partir
deste mesmo pipe.
*/

int main(int argc, int argv[]) {
    int bytes_read;
    char buf[1024];

    int fd2 = open("fifo", O_RDONLY);

    while((bytes_read=read(fd2, buf, 1024))>0) {
        write(1, buf, bytes_read);
    }

    close(fd2);
    
    return 0;
}
