#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fd, char *line, size_t size) {
    int i=0;

    while(i<size && (read(fd, line+i, 1))>0) {
        if(line[i]=='\n') return i+1;
        i++;
    }
    return i;
}

