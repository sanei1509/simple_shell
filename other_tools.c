#include "main.h"

/**
**_strdup - function that return a pointer to str_copy
*@str: receive a pointer to a string
*Return: pointer to a char or null
*/
char *_strdup(char *str)
{
	char *copy_of_str;
	unsigned int i = 0;
	unsigned int ld = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[ld] != '\0')
	{
		ld++;
	}
	ld++;

	copy_of_str = malloc(sizeof(char) * ld);
	if (copy_of_str == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < ld; i++)
		{
			copy_of_str[i] = str[i];
		}

	return (copy_of_str);
	}
}

/**
*_isalpha - return one if c is lowercase else return zero
*@c: number for evaluate
*Return: 0
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *getpadre_id - get id of the padrei
 *Return: padre id
 */
int getpadre_id(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	return (my_ppid);
}

/**
 *gethijo_id - get id of the hijo
 *Return: return the hijo id
 */
int gethijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	return (my_pid);
}

/**
 *ctrl_c - the cntrlc built
 *@signal: signal
 */
void ctrl_c(int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
