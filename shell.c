#include "main.h"
/**
*main - our simple shell
*@argv: argv
*@env: env
*@argc: atributo
*Return: 1
**/
int main(int __attribute__((unused)) argc, char __attribute__((unused))*argv[],
	char **env)
{
	char *path = NULL, *path_comando = NULL, **array_path = NULL;
	ssize_t bytes_leidos = 0;
	size_t numero_bytes = 0;
	char **array = NULL, *cadena = NULL;

	while (1)
	{
		signal(SIGINT, controlar_ctrlc);
		modo_no_interactivo();
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (bytes_leidos == -1 || cadena[0] == EOF || _strcmp("exit\n", cadena) == 0)
			break;
		else if (_strcmp("env\n", cadena) == 0)
		{
			_getenv(env);
			continue;
		}
		else if (cadena[0] == '\n')
		{
			free(cadena), cadena = NULL;
			continue;
		}
		else if (verifica_caracteres(cadena) == -1)
			continue;
		else
		{
			path = find_PATH(env);
			array_path = cargar_paths(path, array_path), array = cargar(cadena, array);
			path_comando = verifica(array_path, array[0]);
			if (cadena[0] == '/')
			{
				ejecutar(array, cadena, env, cadena);
				continue;
			}
			if (path_comando == NULL)
			{
				perror(" ERROR");
				continue;
			}
			else
				ejecutar(array, path_comando, env, cadena);
			bytes_leidos = 0, cadena = NULL;
		}
	}
	free(array_path), free(cadena), free(array);
	return (0);
}
