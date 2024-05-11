/*
    6. 
    Write a slight modification of the previous program, this time using waitpid() instead of wait().
    When would waitpid() be useful?
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){

    printf("Parent\n");

    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed. \n");
        return 0;
    }

    if (new_pid == 0){
        printf("Child\n");
        return 0;
    }

    waitpid(-1, NULL, 0);
    printf("Parent\n");
    return 0;

    return 0;
}