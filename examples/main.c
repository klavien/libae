// gcc -o test *.c -I../ -L../lib -lae


#include "ae.h"
#include <stdio.h>

static int timeProc(struct aeEventLoop *eventLoop, long long id, void *clientData)
{
    printf("this is a timer proc!\n");
    aeDeleteTimeEvent(eventLoop, id);
    return 0;
}
static void beforeSleepProc(struct aeEventLoop *eventLoop)
{
    printf("this run before timer proc!\n");
}
static void afterSleepProc(struct aeEventLoop *eventLoop)
{
    printf("this run after timer proc!\n");
}

int main()
{
    aeEventLoop *loop=aeCreateEventLoop(1024);
    aeCreateTimeEvent(loop,1000,timeProc,NULL,NULL);
    //aeSetBeforeSleepProc(loop, beforeSleepProc);
    //aeSetAfterSleepProc(loop, afterSleepProc);
    aeMain(loop);
    return 0;
}

