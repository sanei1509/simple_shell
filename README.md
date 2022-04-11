<img src= "https://blog.holbertonschool.com/wp-content/uploads/2020/04/unnamed-2.png" width= 23% >

# Simple Shell 
The objective of this project is to make our own shell, it consist on a basic shell that can run commands such as ("ls" "pwd" "echo") with their flags. It is based on a shell and should work like it but it is not as well optimized as the original shell. The simple shell is our last project for the first trimester at **Holberton School!**

## Compilation

To compile our program we are using a **GNU Compiler Collection** (**GCC**) over a Basic Ubuntu 20.04 with the following command:  
``` 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

To start the simple shell just need to write:
./hsh
```
## Memory managment

we try to adjust the memory usage as much as possible with the use of malloc, calloc, free.
we use a debugging tool such as valgrind, with the following command:

````c
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./name_of_executable_file

````


## Functions used

````c
int  _putchar(char c);
int  _strncmp(const  char s1[], const  char s2[], size_t n);
char *_strcat(char *dest, char *src);
int  _strcmp(char *s1, char *s2);
int  _strlen(char *s);
int  count_paths(char *aux_line);
int  count_espacios(char *aux_line);
int getpadre_id(void);
int gethijo_id(void);
void ctrl_c (int signal);
char **return_env(char **environ);
char *_getenv(char *var, char **environ);
char **create_aux (char **aux1, char **env_aux);
char* compare_path(char **array, char *cmd);
````

## Features
- Execute the command without full path Ex: ls -l /tmp
- Execute the command with full path Ex: /bin/ls -l /tmp
- Ctrl D = End of file
- Ctrl C remains in the shell
- If user writes "env" prints the current environment
- If user writes "exit" leaves simple shell

## Examples

```bash
$ /bin/ls
hsh  main.h  other_tools.c  path_tools.c  string_tools.c  simple_shell.c
```

```bash
$ env
*prints whole environment*
```
## Authors
This simple shell was create by:
[Santiago Neira](https://github.com/sanei1509)
and
[Tarik Calixto](https://github.com/tarikaudi)
