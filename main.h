#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H


/*libraries can we will need*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/*own tool prototypes*/
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int getpadre_id(void);
int gethijo_id(void);

char* _getenv(char *var, char **environ);
char** create_aux (char **aux1, char **env_aux)
char* compare_path(char **array, char *cmd);


#endif


