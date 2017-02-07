#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <terminals.h>

int WriteTerminal(int term, char *buf, int buflen);
int ReadTerminal(int term, char *buf, int buflen);
int InitTerminal(int term);
int InitTerminalDriver(void);

/**
* If you make your input buffer very small, you can type and 
* test whether the full buffer condition is handled properly.
*/
int 
main(int argc, char **argv) {

	InitTerminalDriver();

	InitTerminal(1);

	HardwareOutputSpeed(1, 2000);

	sleep(20);

	exit(0);
}