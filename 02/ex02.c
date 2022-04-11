#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int pid=0;

    if((pid=fork())==0) {
        printf("pid: %d\n", getpid());
        printf("ppid: %d\n", getppid());
    }
    else {
        printf("pid: %d\n", getpid());
        printf("ppid: %d\n", getppid());
        printf("child: %d\n", pid);
    }
    return 0;
}
