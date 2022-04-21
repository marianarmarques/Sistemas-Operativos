#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

/*
O primeiro cria um pipe com nome “fifo”.
*/

int main(int argc, int argv[]) {
    if(mkfifo("fifo", 0777)==-1) perror("mkfifo");
    
    return 0;
}