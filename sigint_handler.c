#include "main.h"

/**
*sigint_handler - handle the SIGINT signal
*@sig: contrl + c signal
*Return: void
*/

void sigint_handler(int sig __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "($) ", 4);
}
