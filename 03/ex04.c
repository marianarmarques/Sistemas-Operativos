#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int i=0, status;


    char *args[20], 
         *tokens = strtok(argv[1], " ");

    while(tokens) {
        args[i++]= tokens;
        tokens = strtok(NULL, " ");
    }
    args[i]=NULL;

    if(fork()==0) {
        execvp(args[0], args);
        _exit(1); 
    }

    while(wait(&status)!=-1) {
        if(WEXITSTATUS(status)==1) printf("Erro\n");
    }

    return 0;
}