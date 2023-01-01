#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char **tokenize_string(char *, ssize_t);
int exec_command(char **, char **, int);
char *get_location(char *command);
void sigint_handler(int);
extern char **environ;
void env_command(void);
char *_strcpy(char *, char *);
void _puts(char *);
int _strlen(char *);
char *_strdup(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
int _putchar(char);
#endif
