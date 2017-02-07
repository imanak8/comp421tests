#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>

void reader(void *);
void reader2(void *);
void reader3(void *);
void reader4(void *);

char buf1[2];
char buf2[10];
char buf3[10];
char buf4[10];

/**
* Hi World example from the lab handout.
*/
int main(int argc, char **argv)
{
	InitTerminalDriver();
    InitTerminal(0);

	ThreadCreate(reader, NULL);
	ThreadCreate(reader2, NULL);
	
	ThreadCreate(reader3, NULL);
	ThreadCreate(reader4, NULL);

    ThreadWaitAll();

    exit(0);
}

void
reader(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(0, buf1, 2);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader2(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(0, buf2, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader3(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(0, buf3, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader4(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(0, buf4, 10);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}