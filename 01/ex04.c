#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


ssize_t readln(int fd, char *line, size_t size) {
    int i=0;

    while(i<size && (read(fd, line+i, 1))>0) {
        if(line[i]=='\n') return i+1;
        i++;
    }
    return i;
}

int main() {
    int bytes_read, lines=1;
    char buffer[1024];
    char newBuffer[1024]={};

    while((bytes_read=readln(0, buffer, 1024))>0) {
        
        sprintf(newBuffer, "\t%d %s\n", lines++, buffer);
        write(1, newBuffer, bytes_read);
    }
}