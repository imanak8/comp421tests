#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int WriteTerminal(int term, char *buf, int buflen);
int ReadTerminal(int term, char *buf, int buflen);
int InitTerminal(int term);
int InitTerminalDriver(void);

/**
* Test echo. 
*/
int 
main(int argc, char **argv) {

	InitTerminalDriver();

	InitTerminal(1);

	sleep(20);

	exit(0);
}