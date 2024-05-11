/*
    5. 
    Now write a program that uses wait() to wait for the child process to finish in the parent. 
    What does wait() return? What happens if you use wait() in the child?
*/

#include <unistd.h>
#include <stdio.h>
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
        int w_ret = wait(NULL);
        printf("wait return value from child: %d \n", w_ret);
        return 0;
    }

    int w_ret = wait(NULL);
    printf("Parent\n");
    printf("wait return value from parent: %d \n", w_ret);
    return 0;
}