#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]) {

    int i, status;

    for(i=1; i<=10; i++) {
        if(fork()==0) _exit(i);
    }

    while(wait(&status)!= -1) {
        printf("%d\n", WEXITSTATUS(status));
    }
    return 0;
}