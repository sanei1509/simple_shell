#include "main.h"

/**
*count_paths - cuenta las rutas el array
*@aux_line: aux que recibe las rutas tokenizadas
*Return: return the number of routs
*/

int count_paths(char *aux_line)
{
	int i = 0, cont = 0;

	for (i = 0; aux_line[i] != '\0'; i++)
	{
		if (aux_line[i] == ':')
			cont++;
	}
	return (cont + 1);
}

/**
*_getenv - return the full content of environmennts var PATH
*@var : string of the name of variable that we want get
*@enviro : list with the environments data
*Return: NULL or the complete environment
*/
char *_getenv(char *var, char **enviro)
{
	unsigned int i = 0;
	unsigned int len = _strlen(var);

	if (!enviro || !*var || strchr(var, '='))
	{
		return (NULL);
	}
	else
	{
		while (enviro[i] && (enviro[i][len] != '=' || _strncmp(var, enviro[i], len)))
			i++;
	}
	return ((enviro[i]) ? (enviro[i] + len + 1) : (NULL));
}

/**
 *retur_env - return all environment variables
 *@environ: variable that stores all environment variables
 *Return: 0
*/
char **retur_env(char **environ)
{
	char **s = environ;

	for (; *s; s++)
	{
		/*printf("%s\n", *s);*/
	}

	return (0);
}


/**
***create_aux - take a empty array to fill with the paths
*@aux1 : empty array from main function
*@env_aux : complete list of environments
*Return: 0
*/

char **create_aux(char **array_tokens, char **env_aux)
{
	char *tokenized = NULL, *var = "PATH", *path = NULL;
	int cont = 0, sizepath = 0;

	path = _getenv(var, env_aux);
	sizepath = count_paths(path);
	/*array_tokens = malloc(sizeof(char *) * sizepath + 1);*/
	array_tokens = calloc(sizeof(char *), sizepath + 1);
	tokenized = strtok(path, ":");

	while (tokenized != NULL || cont < sizepath)
	{
		array_tokens[cont] = tokenized;
		cont++;
		tokenized = strtok(NULL, ":");
	}
	return (array_tokens);
}

/**
 *compare_path - function used to compare and concatenate command with path
 *@array: array that is loaded with the paths
 *@cmd: variable that contains the command
 *Return: return the array loaded
 */
char *compare_path(char **array, char *cmd)
{
	struct stat buf;
	char *str = NULL, *path_cmd = NULL;
	int i = 0;

	str = _strcat("/", cmd);

	for (i = 0; array[i]; i++)
	{
		path_cmd = _strcat(array[i], str);
		if (stat(path_cmd, &buf) == 0)
		{
			return (path_cmd);
		}
	}
	
	free(str);
	return (NULL);
}
