#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]) {
    
    int lin = atoi(argv[1]), col = atoi(argv[2]), m[lin][col], i, j, found=-1, status;

    //generate matrix
    for(i=0; i<lin; i++) {
        for(j=0; j<col; j++) {
            m[i][j] = rand()%100;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    //generate forks per line
    for(i=0; i<lin; i++) {
        if(fork()==0) {
            for(j=0; j<col; j++) {
                if(m[i][j]==atoi(argv[3])) _exit(1);
            }
            _exit(0);
        }
    }

    while(wait(&status)!=-1) {
        if(WEXITSTATUS(status)==1) found=1;
    }

    printf("%d\n", found);
    return 0;
}