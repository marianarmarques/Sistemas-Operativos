#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct person {
    char name[20];
    int age;
} Person; 

int main(int argc, char * argv[]) {


    if((strcmp(argv[1], "-i"))==0) {
        int fd1 = open("pessoas.bin", O_CREAT | O_TRUNC | O_WRONLY, 0600);

        Person p;
        strcpy(p.name, argv[2]);
        p.age = atoi(argv[3]);

        write(fd1, &p, sizeof(struct person));
    }
    return 0;
}