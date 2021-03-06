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
	char **array = NULL, *cadena = NULL;

	while (1)
	{	signal(SIGINT, controlar_ctrlc);
		modo_no_interactivo();
		bytes_leidos = getline(&cadena, &numero_bytes, stdin);
		if (bytes_leidos == -1)
			break;
		caso = casos_border(cadena);
		if (caso == 1)
			break;
		else if (caso == 2)
			continue;
		else
		{
			path = find_PATH(environ);
			array_path = cargar_paths(path, array_path), array = cargar(cadena, array);
			if (cadena[0] == '/')
			{
				if (stat(cadena, &buf) == 0)
				{
					ejecutar(array, cadena, environ, cadena);
					continue; }
				perror(cadena);
				continue; }
			path_comando = verifica(array_path, array[0]);
			if (path_comando == NULL)
			{
				perror("./hsh");
				continue;	}
			else
				ejecutar(array, path_comando, environ, cadena);
			free(path);
			freearray(array_path); } }
	free(array_path), free(cadena), free(array);
return (0); }
