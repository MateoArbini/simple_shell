#include "main.h"
/**
 *ContTokens - Function that prints the amount of Tokens
 *@cadena1: Parameter given by the user
 *@separador: separador
 *Return: Cont
 **/

int ContTokens(char *cadena1, char *separador)
{
	int cont = 0;
	char *token1 = NULL;

	token1 = strtok(cadena1, separador);
	while (token1 != NULL)
	{
		token1 = strtok(NULL, separador);
		cont++;
	}
	return (cont);
}
/**
 *find_PATH - Finds the PATH in the enviroment command
 *@env: environ command
 *Return: Ruta, which is the PATH
 **/
char *find_PATH(char **env)
{
	char *copy = NULL;
	char *retorno = NULL;
	int iter = 0;

	while (env[iter])
	{
		copy = _strdup(env[iter]);
		if (env[iter][0] == 'P' && env[iter][1] == 'A')
		{
			retorno = strtok(copy, "=");
			retorno = strtok(NULL, "=");
			break;
		}
		else
		{
			iter++;
		}
		free(copy);
		copy = NULL;
	}
	return (retorno);
}
/**
 *cargar - Function that returns the array to execute
 *@cadena: string given by the user
 *@array: array of strings given by the user
 *Return: Array
 **/
char **cargar(char *cadena, char **array)
{
	int iter = 0;
	char *copycadena = NULL;
	int tokens = 0;
	char *token = NULL;

	copycadena = _strdup(cadena);
	cadena = strtok(cadena, "\n");
	cadena = strtok(cadena, "\t");
	tokens = ContTokens(copycadena, " ");
	array = calloc(tokens + 1, sizeof(char *));
	token = strtok(cadena, " ");

	while (token != NULL && iter < tokens) /*Lleno el array*/
	{
		array[iter] = token;
		iter++;
		token = strtok(NULL, " ");
	}
	free(copycadena);
	array[tokens] = NULL;
	iter = 0;
	return (array);
}
/**
 *cargar_paths - function
 *@path: path
 *@array: array
 *Return: Array
 **/
char **cargar_paths(char *path, char **array)
{
	int iter = 0;
	char *copypath = NULL;
	char *path2 = _strdup(path);
	int tokens = 0;
	char *token = NULL;
	char *copytoken = NULL;

	copypath = _strdup(path);
	tokens = ContTokens(copypath, ":");
	array = calloc(tokens + 1, sizeof(char *));
	token = strtok(path2, ":");
	while (token != NULL && iter < tokens) /*Lleno el array*/
	{
		copytoken = _strdup(token);
		token = _strcat(copytoken, "/");
		array[iter] = token;
		iter++;
		token = strtok(NULL, ":");
	}
	free(copypath);
	array[tokens] = NULL;
	free(path2);
	return (array);
}
/**
 *ejecutar - ejecutar function
 *@array: array
 *@path_comando: path_comando
 *@env: env
 *@cadena: cadena
 **/
void ejecutar(char **array, char *path_comando, char **env, char *cadena)
{
	pid_t hijo;

	array[0] = path_comando;
	hijo = fork();
	if (hijo == 0) /*Dentro del hijo*/
	{
		if (execve(array[0], array, env) == -1) /*Tratamos de ejecutar el coman*/
		{
			free(cadena);
			perror(" ERROR");
		}
	}
	else/*Estoy en el padre*/
		wait(NULL);
}

