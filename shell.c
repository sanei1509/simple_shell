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
void execute_cmd(char *line, char *cmd, char **array, char **env)
{
	if ((execve(cmd, array, env) == -1))
	{
		free(line);
		perror("Error");
		exit(0);
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

/**
*main - take the input command of the user
*@ac: unused variable
*@av: unsued pointer to pointer
*@env: environemnt varia
*Return: 0
*/
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	int bytes_read = 0;
	size_t size = 0;
	char *line_read = NULL, *ret_pathcmd = NULL;
	char **argv = NULL, **arr_paths = NULL;
	pid_t forkResultado = 0;

	arr_paths = create_aux(arr_paths, env);
	while (1)
	{
		signal(SIGINT, ctrl_c);
		interactive_mode();

		bytes_read = getline(&line_read, &size, stdin);

		if (line_read[0] == '\n')
			continue;
		if (bytes_read == -1 || line_read[0] == EOF)
			break;
		else
		{
			argv = parser_line(argv, line_read);
			ret_pathcmd = compare_path(arr_paths, argv[0]);

			if (line_read != NULL)
			{
				if ((_strcmp(argv[0], "exit") == 0) || (_strcmp(argv[0], "EOF") == 0))
					break;
				if (_strcmp(argv[0], "env") == 0)
				{
					retur_env(environ);
					continue;
				}

				if (_isalpha(argv[0][0]) == 1)
				{
					if (ret_pathcmd == NULL)
					{
						perror("Error");
						continue;
					}
					argv[0] = ret_pathcmd;
					forkResultado = fork();
					(forkResultado == 0) ? execute_cmd(line_read, argv[0], argv, environ) :
														(void) wait(NULL); continue;
				}
				else
				{
					forkResultado = fork();
					(forkResultado == 0) ? execute_cmd(line_read, argv[0], argv, environ) :
														(void) wait(NULL); continue;
				}
			}
			else
			{
				free(line_read), line_read = NULL;
			       	continue;
			}
			free(arr_paths);
		}
		clean_everything(line_read, argv);
	}
	clean_everything(line_read, argv);
	return (0);
}
