#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    char buf[1024];
    int bytes_read;
    
    if(mkfifo("fifo", 0777)<0) perror("mkfifo");

    int fd_log = open("log.txt", O_CREAT | O_TRUNC | O_WRONLY, 0600);
    int fd_npipe = open("fifo", O_RDONLY); //server lê do pipe

    while((bytes_read=read(fd_npipe, buf, 1024))>0) {
        write(fd_log, buf, bytes_read);
    }
    close(fd_log);
    close(fd_npipe);

    return 0;
}