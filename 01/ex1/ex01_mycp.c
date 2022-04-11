#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char * argv[]) {

    // 1. Abrir ficheiros (Ficheiro origem argv[0] e ficheiro destino (argv[1])
    int source_fd = open(argv[1], O_RDONLY);

    if(source_fd<0) {
        perror("Open");
        return 1;
    }

    int target_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0600);

    if(target_fd<0){
        perror("Open");
        return 1;
    }
    
    // 2. Criar um buffer de tamanho X 
    char buffer[1024];

    // 3. Ler/escrever até read=0
    int bytes_read=0;

    if((bytes_read = read(source_fd, buffer, 1024))>0){
        printf("%d\n",bytes_read);
        write(target_fd, buffer, bytes_read); 
    }
    
    // 4. Fechar descritores
    close(source_fd);
    close(target_fd);

    return 0;
}