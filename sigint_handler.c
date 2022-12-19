#include "main.h"

/**
*sigint_handler - handle the SIGINT signal
*@sig: contrl + c signal
*Return: void
*/

void sigint_handler(int sig)
{
	printf("\n");
	fflush(stdout);
}
