/*
    8. 
    Write a program that creates two children, and connects the standard output of one to the 
        standard input of the other, using the pipe() system call.
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){

    int pipefd[2];
    pipe2(pipefd, O_NONBLOCK);

    pid_t child1_pid = fork();

    if (child1_pid < 0){
        printf("fork() 1 failed.\n");
        return 0;
    }

    if (child1_pid == 0){
        dup2(pipefd[0], STDIN_FILENO);
        char buf[50] = {'\0'} ;
        //execlp("cat", "cat", NULL);
        while(strlen(buf) == 0){
            read(STDIN_FILENO, buf, 20);
        }
        printf("this printf call is from child 1 ,,, read message: %s", buf);
    }

    pid_t child2_pid = fork();

    if (child2_pid < 0){
        printf("fork() 2 failed.\n");
        return 0;
    }

    if (child2_pid == 0){
        dup2(pipefd[1], STDOUT_FILENO);
        printf("hello from child 2\n");
        return 0;
    }

    wait(NULL);
    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}