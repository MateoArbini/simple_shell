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
	int iter = 0;

	while (env[iter])
	{
		if (env[iter][0] == 'P' && env[iter][1] == 'A')
		{
			copy = calloc((_strlen(env[iter]) - 5), sizeof(char));
			copy = _strcpy(copy, env[iter] + 5);
			break;
		}
		else
			iter++;
	}
	return (copy);
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

	copycadena = calloc(_strlen(cadena), sizeof(char));
	copycadena = strcpy(copycadena, cadena);
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
	free(token);
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
	char *path2 = NULL;
	int tokens = 0;
	char *token = NULL;
	char *copy = NULL;

	path2 = calloc(_strlen(path), sizeof(char));
	path2 = _strcpy(path2, path);
	tokens = ContTokens(path2, ":");
	array = calloc(tokens + 1, sizeof(char *));
	token = strtok(path, ":");
	while (iter < tokens)
	{
		copy = calloc(_strlen(token), sizeof(char));
		copy = _strcpy(copy, token);
		token = _strcat(copy, "/");
		array[iter] = copy;
		token = strtok(NULL, ":");
		iter++;
	}
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

