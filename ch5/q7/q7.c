/*
    7. 
    Write a program that creates a child process, and then in the child closes 
        standard output (STDOUT FILENO). 
    What happens if the child calls printf() to print some output after closing the descriptor?
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(){

    printf("parent 1\n");
    
    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed. \n");
        return 0;
    }

    if (new_pid == 0){
        printf("child 1\n");
        close(STDOUT_FILENO);
        printf("child 2\n");
    }

    wait(NULL);
    printf("parent 2\n");
    return 0;
}