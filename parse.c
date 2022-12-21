#include "main.h"

/**
  *parse - function to break the string input into tokens
  *@command: command input
  *
  *Return: void
  */
void parse(char *command, int n)
{
	char **argv;
	char *delim = " \n";
	int total_token = 0;
	int i;
	char *token;
	char *command_cpy = malloc(sizeof(char) * n);

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
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	exe_cute(argv);

	free(argv);
	free(command_cpy);
}
