# Welcome to our simple_shell Project!

<img src= "https://blog.holbertonschool.com/wp-content/uploads/2020/04/unnamed-2.png" width= 39% >



Hello everyone! This is our “simple_shell” project. Our task was to create a replica of a console, which could read a command line, and execute them. To do this, we had to investigate various issues that occur behind the execution of a command, and that we do not see. We had to implement the use of functions such as "execve", "getline", among others, understand how they work, and from there, with the tools we had and that we had to learn, create our own console.


# Functions

`````
extern char **environ;
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
`````

# Compilation
The command we used to compile our console shell was:

`````
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
`````

# Testing
As a part of this project, our Shell must work like this in interactive mode:
`````
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
`````

But it must work also in non-interactive mode:
`````
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
`````

# Style
Our code should use the **Betty** style, and it will be checked using:

[betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")
[betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")

# Flowchart

<img src=https://user-images.githubusercontent.com/98335785/162879103-5e58a581-8519-404b-bd19-ed3752cffc8c.png>

# Authors
[Mateo Arbini](https://www.linkedin.com/in/mateo-arbini-1493691a8/)
[Valentín Repetto](https://www.linkedin.com/in/valentin-repetto-6aa6711a0/)

Holberton School Cohort 17
