#include "main.h"
/**
*_strcmp- asd
*@s1: asd
*@s2: asd
*Return: asd
**/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 *_strcat - sss
 *@dest: 122
 *@src: 1223
 *Return: dest
 **/
char *_strcat(char *dest, char *src)
{
	int contdest = _strlen(dest), a = 0, c = 0;
	int contsrc = _strlen(src);

	for (a = contdest; a < contdest + contsrc; a++)
	{
		if (c <= contsrc)
		{
		dest[a] = src[c];
		c++;
		}
	}
	return (dest);
}

/**
 *_strlen - 123
 *@s: 123
 *Return: 12
 **/
int _strlen(char *s)
{
		int cont = 0;
		char *a = NULL;

		a = s;

		while (*a != 0)
		{
			a++;
			cont++;
		}
		return (cont);
}
/**
 *_strdup - malloc
 *@str: char
 *Return: char
 **/
char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *array = NULL;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;

	array = calloc(i + 1, sizeof(char));
	if (array == NULL)
		return (0);

	for (j = 0; j < i; j++)
		array[j] = str[j];
	return (array);
}
