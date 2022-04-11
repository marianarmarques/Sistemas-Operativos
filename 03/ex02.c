#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int pid;

    if((pid=fork())==0) {
        if (execl("/bin/ls", "/bin/ls", "-l", NULL)<0) perror("execl");
        _exit(0);
    }
    
    printf("done\n");
}