/*
    1. 
    Write a program that calls fork(). 
    Before calling fork(), have the main process access a variable (e.g., x) 
        and set its value to something (e.g., 100). 
    What value is the variable in the child process?
    What happens to the variable when both the child and parent change the value of x?
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int x = 10;

    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed. \n");
        return 0;
    }

    if (new_pid == 0){
        x++;
        printf("x value from child: %d\n", x);
        return 0;
    }
    wait(NULL);
    printf("x value from parent: %d\n", x);
    return 0;
}