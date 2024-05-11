/*
    2. 
    Write a program that opens a file (with the open() system call) 
        and then calls fork() to create a new process. 
    Can both the child and parent access the file descriptor returned by open()? 
    What happens when they are writing to the file concurrently, i.e., at the same time?
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main(){

    int fd = open("./test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);

    if (fd < 0){
        printf("open() failed\n");
        return 0;
    }

    pid_t new_pid = fork();

    if (new_pid < 0){
        printf("fork() failed\n");
        close(fd);
        return 0;
    }

    if (new_pid == 0){
        char* x = "hello from child process\n";
        write(fd, x, strlen(x));
        return 0;
    }

    char* x = "hello from parent process\n";
    write(fd, x, strlen(x));

    close(fd);
    return 0;
}