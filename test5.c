#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <hardware.h>

void reader(void *);
void reader2(void *);
void writer(void *);
void statistics(void *);

char string[] = "abcdefghijklmnopqrstuvwxyz";
int length = sizeof(string) - 1;
struct termstat stats[NUM_TERMINALS];

/**
* This tests multiple threads and multiple terminals.
*/
int main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);
    InitTerminal(3);

    if (argc > 1) HardwareOutputSpeed(1, atoi(argv[1]));
    if (argc > 2) HardwareInputSpeed(1, atoi(argv[2]));

    ThreadCreate(reader, NULL);
    ThreadCreate(reader, NULL);
    ThreadCreate(writer, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(writer, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(reader, NULL);
    ThreadCreate(statistics, NULL);

    ThreadWaitAll();

    exit(0);
}

void
reader(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, string, 2);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
reader2(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(2, string, 3);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}


void
writer(void *arg)
{
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(1, string, length);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void
writer2(void *arg)
{
    int status;

    printf("Doing WriteTerminal... '");
    fflush(stdout);
    status = WriteTerminal(3, string, length);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}

void statistics(void *arg) {
    int status;

    printf("Doing TerminalDriverStatistics... ");
    fflush(stdout);
    status = TerminalDriverStatistics(stats);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}
