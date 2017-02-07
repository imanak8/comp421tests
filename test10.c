#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <terminals.h>

void reader(void *);

char buf1[] = "abcdefj";

/**
* Three possible tests: 
* (1) Type "abcdefghij\n" before Doing ReadTerminal... appears.
*	  ReadTerminal should be satisfied immediately after beginning.
* (2) Wait until Doing ReadTerminal... appears. Then type "abcdefg\n"
*	  This tests normal ReadTerminal functionality.
* (3) Type "abcdefg" before Doing ReadTerminal... appears. Type "\n" after.
* 	  Read terminal should read from the abcdefg string. 
*/
int 
main(int argc, char **argv) {

	InitTerminalDriver();

	InitTerminal(1);

	// Type enough characters before call to read terminal begins.
	sleep(10);

	ThreadCreate(reader, NULL);

	sleep(2);

	exit(0);
}

void
reader(void *arg)
{
    int status;

    printf("Doing ReadTerminal... '");
    fflush(stdout);
    status = ReadTerminal(1, buf1, 2);
    printf("'. Done: status = %d.\n", status);
    fflush(stdout);
}