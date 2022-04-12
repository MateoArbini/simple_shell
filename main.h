#ifndef MAIN_H
#define MAIN_H
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
extern char **environ;
void freearray(char **array);
char *_strcpy(char *dest, char *src);
int ContTokens(char *cadena1, char *separador);
char *find_PATH(char **env);
char **cargar(char *cadena, char **array);
char **cargar_paths(char *path, char **array);
char *verifica(char **path, char *comando);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int verifica_exit(char *cadena);
int verifica_caracteres(char *cadena);
void _getenv(void);
int verifica_env(char *cadena);
void controlar_ctrlc(int sig);
void ejecutar(char **array, char *path_comando, char **env, char *cadena);
void modo_no_interactivo(void);
int casos_border(char *cadena);
#endif
