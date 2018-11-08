#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
static void sighandler(int signo){
    if(signo == SIGINT){
        printf("\nYou have exited the process using a keyboard interrupt\n");
        exit(0);
    }
    else if(signo == SIGUSR1){
        printf("\nThe parent process is %d\n\n",getppid());

    }
}

int main(){
    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);
    while(1){
        printf("The pid of this process is %d\n",getpid());
        sleep(1);
    }
}
