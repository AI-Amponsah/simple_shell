#include "main.h"

/**
  *execute - excutes the commands
  * @argv: Argument vector
  *
  *Return: void
  */

void execute(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("execution failed");
		};
	}

}
