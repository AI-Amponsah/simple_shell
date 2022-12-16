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
	char*command;
	size_t n;
	int char_read;
	(void)argc, (void)argv, (void)envp;

	do {
	printf("alx_shell_$ ");
	char_read = getline(&command, &n, stdin);
	printf("%d\n", char_read);
	printf("%s", command);
	}while (1);

	return (0);
}
