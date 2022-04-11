#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char * argv[]) {

    // 1. Criar um buffer de tamanho X 
    char buffer[1024];

    // 2. Ler/escrever até read=0
    int bytes_read=0;

    if((bytes_read = read(1, buffer, 1024))>0){
        write(2, buffer, bytes_read); 
    }
}