#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    
    //Option1
    if (execl("/bin/ls", "/bin/ls", "-l", NULL)<0)
        perror("execl");
    
    printf("done\n");
    
    /*

    //Option2
    if (execlp("ls", "ls", "-l", NULL)<0)
        perror("execl");

    //Option3
    char * args[] = {
        "/bin/ls",
        "-l",
        NULL
    };

    if(execv("/bin/ls", args)<0) 
        perror("execv");
        
    */

    return 0;
}