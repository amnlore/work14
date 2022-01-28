#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int x = open("file", O_APPEND | O_CREAT | O_WRONLY, 0644);
        char c[] = "process is done";
        write(x, c, sizeof(c));
        exit(0);
    }
    if (signo == SIGUSR1) {
        printf("%d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while(1) {
        printf("%d\n", getpid());
        sleep(1);
    }
    return 0;
}
