#include "main.h"

/**
  *main - Entry point function
  *@argv: Argument vector
  *@argc: Argument counter
  *
  *Return: Always 0
  */

int main(int argc, char **argv, char **envp)
{
	char*command = NULL;
	char *command_cpy  = NULL;
	size_t n = 0;
	char *token;
	int total_token = 0;
	int char_read, i;
	char *delim = "\n";
	(void)argc, (void)envp;

	while (1)
	{
	printf("alx_shell_$ ");
	char_read = getline(&command, &n, stdin);
	printf("%s", command);
	if (char_read == -1)
	{
		return (-1);
	}
	/** allocating space for command */
	command_cpy = malloc(sizeof(char)*char_read);
	if (command_cpy == NULL)
	{
		perror("Space not allocated");
		return (-1);
	}
	/** making a copy of the command and parsing the command usinf strtok */
	strcpy(command_cpy, command);
	token = strtok(command, delim);

	while (token != NULL)
	{
		total_token++;
		token = strtok(NULL, delim);
	}
	total_token++;

	argv = malloc(sizeof(char)*total_token);

	token = strtok(command_cpy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char)*strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	execute(argv);

	}

	free(command_cpy);
	free(argv);

	return (0);
}
