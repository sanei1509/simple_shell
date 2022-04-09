#include "main.h"

/**
**getenv . return the full content of environmennts var PATH
*@var : string of the name of variable that we want get
*@environ : list with the environments data
*Return: NULL or the complete environment
*/
char *_getenv(char *var, char **environ)
{	
	unsigned int i = 0;
	unsigned int len = _strlen(var);
	
	if (!environ || ! *var || strchr(var,'='))
		return (NULL);
	else
	while (environ[i] && (environ[i][len] != '=' || _strncmp(var, environ[i], len)))
		i++;

	return (environ[i]) ? (environ[i] + len + 1) : (NULL);
}


/**
***create_aux - take a empty array to fill with the paths
*@aux1 : empty array from main function
*@env_aux : complete list of environments
*Return: 0
*/

char **create_aux(char **aux1, char **env_aux)
{
	char *tokenized = NULL, *var = "PATH", char *path = NULL;
	int cont = 0, sizepath = 0;

	path = _getenv(var, env_aux);
	sizepath = count_spaces(path);
	aux1 = malloc(sizeof(char *) * sizepath + 1);
	tokenized = strtok(path, ":");

	while (tokenized != NULL || cont < sizepath)
        {
                aux1[cont] = tokenized;
                cont++;
                tokenized= strtok(NULL, ":");
        }
	return (aux1);
}

