#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    char buf[1024];
    int bytes_read;
    
    if(mkfifo("fifo", 0777)<0) perror("mkfifo");

    int fd_npipe = open("fifo", O_WRONLY); //cliente escreve para o pipe

    while((bytes_read=read(0, buf, 1024))>0) {
        write(fd_npipe, buf, bytes_read);
    }
    
    return 0;
}