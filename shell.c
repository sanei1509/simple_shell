#include "main.h"

/**
 *count_espacios - function used to count the spaces changes
 *@aux_line: array that will be the base of
 *Return: return the count of spaces
 */
int count_espacios(char *aux_line)
{
	int s = 0;
	char *aux, *copy_line = strdup(aux_line);

	aux = strtok(copy_line, " ");

	while (aux != NULL)
	{
		s++;
		aux = strtok(NULL, " ");
	}

	return (s);
}

/**
 *parser_line - function to parse the array
 *@array: the array charged with path
 *@line: line line
 *Return: return the array charged
 */
char **parser_line(char **array, char *line)
{
	int count_tokens = 0, i = 0;
	char *token = NULL;

	line = strtok(line, "\n");
	count_tokens = count_espacios(line);
	array = calloc(count_tokens + 1, sizeof(char *));
	token = strtok(line, " ");

	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	return (array);
}

/**
 *execute_cmd - function that executes the commands
 *@line: line line
 *@cmd: command to be executed
 *@array: array with the full path concat
 *@env: env used
 */
void exe_path(char *cmd, char **array, char **env, pid_t forkReturn)
{
	if (forkReturn == 0)
	{
		if ((execve(cmd, array, env) == -1))
		{
			perror("Error");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		return;
	}
}

void val_env_input(char *cmd, char **environ)
{
	if (_strcmp(cmd, "env") == 0)
	{
		retur_env(environ);
		return;
	}
}

 

/**
*interactive_mode - shell with non interactive mode
 */
void interactive_mode(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
}

void execute_cmd(char *cmd, char **arr_paths, pid_t fork_res, char **array, char word)
{

	if(_isalpha(word) == 1)
	{
		if ((compare_path(arr_paths, cmd)) == NULL)
		{
			perror("Error");
			return;
		}
		cmd = compare_path(arr_paths, cmd);
		fork_res = fork();
		printf("creando hijo\n");
		if (fork_res == 0)
		{
			if ((execve(cmd, array, environ) == -1))
			{
				perror("Error");
				exit(0);
			}
		}
	}
	else
	{
		wait (NULL);
		return;
	}
}



/**
*main - take the input command of the user
*@ac: unused variable
*@av: unsued pointer to pointer
*@env: environemnt varia
*Return: 0
*/
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	int bytes_read = 0; size_t size = 0; pid_t fork_res = 0;
	char *line_read = NULL, **argv = NULL, **arr_paths = NULL;

	arr_paths = create_aux(arr_paths, env);
	while (1)
	{
		signal(SIGINT, ctrl_c);
		interactive_mode();

		bytes_read = getline(&line_read, &size, stdin);

		if (line_read[0] == '\n' || line_read[0] == '\t')
			continue;
		if (bytes_read == -1 || line_read[0] == EOF)
			break;
		else
		{
			argv = parser_line(argv, line_read);

			if (line_read != NULL)
			{
				if ((_strcmp(argv[0], "exit") == 0) || (_strcmp(argv[0], "EOF") == 0))
					break;
				val_env_input(argv[0], environ);

				execute_cmd(argv[0], arr_paths, fork_res, argv, argv[0][0]);

				if(_isalpha(argv[0][0]) != 1)
				{
					fork_res = fork();

					printf("Creando hijo para ruta \n");
						exe_path(argv[0], argv, environ, fork_res);
				}
			}
			else
			{
			       	continue;
			}
		}
	}
	return (0);
}
