#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main() {
    int pid;
    pid = fork();
    if(pid == 0) {
        close(1);
        open("output.txt", O_WRONLY | O_CREATE);
        char *argv[] = {"echo", "this", "is", "echo", 0};
        exec("echo", argv);
        fprintf(2, "exec failed\n");
        exit(1);
    } else {
        wait((int *)0);
    }
    exit(0);
}