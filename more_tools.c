#include "main.h"

/**
*clean_everything - function to clear every var
*@line: var to be freed
*@array: array to be freed
*/
void clean_everything(char *line, char **array)
{
	free(line);
	line = NULL;
	free(array);
}

/**
*_putchar - writes the character c to stdout
* @c: The character to print.
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

