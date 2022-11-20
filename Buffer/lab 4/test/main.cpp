#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
 
void alarm_handler(int signo)
{
    printf("Boom!\n");
    exit(0);
}
 
int main(void)
{
    time_t t = 0;
 
    signal(SIGALRM, alarm_handler);
    alarm(5);
    printf("Bomb has been planted.\n");
    while(1) {
        printf("%ld...\n", ++t);
        sleep(1);
    }
    return 0;
}
