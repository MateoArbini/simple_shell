#include "main.h"
/**
*main - our simple shell
*Return: 1
**/
int main(void)
{	char *path = NULL, *path_comando = NULL, **array_path = NULL;
	struct stat buf;
	ssize_t bytes_leidos = 0;
	int caso = 0;
	size_t numero_bytes = 0;
	char **array = NULL, *cadena = NULL, **env = NULL;

	env = environ;
	path = find_PATH(env);
	while (1)
	{	signal(SIGINT, controlar_ctrlc);
		modo_no_interactivo();
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		caso = casos_border(cadena, bytes_leidos);
		if (caso == 1)
			break;
		else if (caso == 2)
			continue;
		else
		{
			array_path = cargar_paths(path, array_path), array = cargar(cadena, array);
			if (cadena[0] == '/')
			{
				if (stat(cadena, &buf) == 0)
				{
					ejecutar(array, cadena, env, cadena);
					continue;
				}
				perror("ERROR");
				continue;
			}
			path_comando = verifica(array_path, array[0]);
			if (path_comando == NULL)
			{
			perror("ERROR");
			continue;	}
			else
				ejecutar(array, path_comando, env, cadena); }
			bytes_leidos = 0, cadena = NULL; }
	free(array_path), free(cadena), free(array);
	return (0);
}
