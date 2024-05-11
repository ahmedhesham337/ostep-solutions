/*
    4. 
    Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. 
    See if you can try all of the variants of exec(), including (on Linux) execl(), execle(),
        execlp(), execv(), execvp(), and execvpe(). 
    Why do you think there are so many variants of the same basic call?
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>


int main(){

    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed.\n");
        return 0;
    }

    if (new_pid == 0){
        //char* args[3];
        //args[0] = strdup("ls");
        //args[1] = strdup("-la");
        //args[2] = NULL;
        //execv("/bin/ls", args);
        execlp("ls", "ls", "-la", NULL);
        return 0;
    }

    return 0;
}