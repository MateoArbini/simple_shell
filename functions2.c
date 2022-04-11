#include "main.h"
/**
 *verifica - verifica el comando
 *@path: array de paths
 *@comando: comando ingresado
 *Return: null o path del comando
 **/
char *verifica(char **path, char *comando)
{
struct stat buf;
char *path2 = NULL;
int iter = 0;

while (path[iter])
{
	path2 = _strcat(path[iter], comando);
	if (stat(path2, &buf) == 0)
		return (path2);
	iter++;
}
return (NULL);
}

/**
 *verifica_caracteres - printea
 *@cadena: texto ingresado
 *Return: 1 o 0
**/
int verifica_caracteres(char *cadena)
{

	int iter = 0;

	while (cadena[iter])
	{
		if (cadena[iter] != ' ' && cadena[iter] != '\n' && cadena[iter] != '\t')
		{
			return (0);
		}
		iter++;
	}
	return (-1);
}
/**
 *_getenv - getenv function
 *@env: env
 **/
void _getenv(char **env)
{
	int iter = 0;

	while (env[iter])
	{
		write(1, env[iter], 2);
		iter++;
	}
}
/**
 *controlar_ctrlc - function
 *@sig: signal
 **/
void controlar_ctrlc(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}
/**
 *modo_no_interactivo - function
 **/
void modo_no_interactivo(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
}
