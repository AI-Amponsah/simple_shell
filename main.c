#include "main.h"
/**
  *main - Entry point function
  *@argv: Argument vector
  *@argc: Argument counter
  *Return: Always 0
  */
int main(int argc, char **argv)
{
	char *command = NULL;
	size_t n = 0;
	ssize_t char_read;
	(void)argc, (void)argv;
	while (1)
	{
	printf("shell~$ ");
	char_read = getline(&command, &n, stdin);
	if (char_read == -1)
	{
		return (-1);
	}
	parse(command, char_read);
	}
	free(command);
	return (0);
}
