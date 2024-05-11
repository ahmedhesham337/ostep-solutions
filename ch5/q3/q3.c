/*
    3. 
    Write another program using fork(). 
    The child process should print “hello”; the parent process should print “goodbye”. 
    You should try to ensure that the child process always prints first; 
        can you do this without calling wait() in the parent?
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

    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed.\n");
        return 0;
    }

    if (new_pid == 0){
        int n = printf("hello\n");
        char nn = (char)(n+0x30);
        write(pipefd[1], &nn, 1);
        return 0;
    }

    char tmp = 0x00;
    
    while(tmp != '6'){
        read(pipefd[0], &tmp, 1);
    }
    
    printf("goodbye\n");

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}