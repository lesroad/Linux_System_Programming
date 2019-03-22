//信号会把睡眠唤醒
//屏蔽过程中有信号不会抵达和被捕捉，当解除屏蔽后本信号会抵达和被捕捉
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
void func1(int signal)
{
	printf("catch sigint\n");
	sleep(3);
}
void func2(int signal)
{
	printf("catch sigquit\n");
	sleep(3);
}

int main(int argc, const char* argv[])
{
    
    

    struct sigaction act1, act2;
    act1.sa_handler = func1;
    sigemptyset(&act1.sa_mask);
    //sigaddset(&act1.sa_mask, SIGQUIT);
    act1.sa_flags = 0;
    sigaction(SIGINT, &act1, NULL);

    act2.sa_handler = func2;
    sigemptyset(&act2.sa_mask);
    //sigaddset(&act2.sa_mask, SIGINT);
    act2.sa_flags = 0;
    sigaction(SIGQUIT, &act2, NULL);

    for(int i = 10; i >= 1; i--)
    {
    	printf("%ds\n", i);
    	sleep(1);
    }

    
    sleep(5);
    return 0;
}
