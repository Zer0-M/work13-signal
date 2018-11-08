#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
static void sighandler(int signo){
    if(signo == SIGINT){
        int fd=open("interruptlog",O_WRONLY|O_APPEND|O_CREAT);
        char buffer[]="Program exited due to SIGINT(keyboard interrupt)\n";
        int byteswrote=write(fd,buffer,strlen(buffer));
        if(byteswrote<0){
            printf("%s\n",strerror(errno));
        }
        printf("\nCheck interruptlog\n");
        close(fd);
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
