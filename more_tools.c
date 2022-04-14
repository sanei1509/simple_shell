#include "main.h"

/**
*validate_input - when is space, tab or enter
*@line: linea leida
*Return: succes(0) or fail(1)
*/
int validate_input(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

/**
 *interactive_mode - shell with non interactive mode
 */
void interactive_mode(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
}

/**
 *count_espacios - function used to count the spaces changes
 *@aux_line: array that will be the base of
 *Return: return the count of spaces
 */
int count_espacios(char *aux_line)
{
	int s = 0;
	char *aux = NULL, *copy_line = _strdup(aux_line);

	aux = strtok(copy_line, " ");

	while (aux != NULL)
	{
		s++;
		aux = strtok(NULL, " ");
	}

	free(copy_line);
	return (s);
}

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
	write(1, &c, 1);

	return (0);
}

