#include "main.h"
/**
  *main - Entry point function
  *@argv: Argument vector
  *@argc: Argument counter
  *Return: Always 0
  */
int main(int argc, char **argv)
{
	char *command = NULL, *command_cpy  = NULL;
	size_t n = 0;
	char *token;
	ssize_t char_read;
	int i; 
	int total_token = 0;
	const char *delim = " \n";

	(void)argc;
	while (1)
	{
	printf("_shell:$ ");
	char_read = getline(&command, &n, stdin);
	if (char_read == -1)
	{
		return (-1);
	}
	command_cpy = malloc(sizeof(char) * char_read);
	if (command_cpy == NULL)
	{
		return (-1);
	}
	strcpy(command_cpy, command);
	token = strtok(command, delim);
	while (token != NULL)
	{
		total_token++;
		token = strtok(NULL, delim);
	}
	total_token++;
	argv = malloc(sizeof(char *) * total_token);
	token = strtok(command_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		printf("%s\n", argv[i]);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	/*exe_cute(argv);*/
	}
	free(command);
	free(command_cpy);
	return (0);
}
