#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer(void *);

char string[] = "abcdefghijklmnopqrstuvwxyz";
int length = sizeof(string) - 1;

/**
* Make output buffer small--of about size 5. 
* Test whether full output buffer logic works. 
*/
int main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);

    sleep(1);

    ThreadCreate(writer, NULL);
    ThreadCreate(writer, NULL);

    ThreadWaitAll();

    exit(0);
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
