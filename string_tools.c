#include "main.h"

/**
 *-putchar - writes the character c to stdout
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* *_strcat - function tha concatenate two strings
* @dest : place where append de src string
* @src: place of the string for append
* Return: pointer to dest
*/

*_strcat(char *dest, char *src)
{
	char *start = NULL;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	start = dest;
	while (*start != '\0')
		start++;
	while (*src != '\0')
		*start++ = *src++;
	*start = '\0';
	return (dest);
}


/**
*_strlen - swaps the value of two integers
* @s: The pointer value one
* Return: c
*/
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;

	return (c);
}



/** 
 * *_strcpy - return the copy pointed string por src
 * @dest: copy source to here
 * @src: source for copy
 * Return: copy of src
 */

char *_strcpy(char *dest, char *src)
{
	int length = 0;
	int i;

	while (src[length] != '\0')
		length++;

	for (i = 0; i <= length; i++)
		dest[i] = src[i];

	return (dest);

}

/**
* _strcmp - function that compares two strings
* @s1 : number one to compare
* @s2: number two to compare
* Return: 0 is numbers are equal result of sustraction if not.
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

