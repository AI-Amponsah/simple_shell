#include "main.h"

/**
  *execute - excutes the commands
  * @argv: Argument vector
  *
  *Return: void
  */

void exe_cute(char **argv)
{
	char *command = NULL;
	char *real_command;

	if (argv)
	{
		command = argv[0];
		real_command = find_path(command);

		if (execve(real_command, argv, NULL) == -1)
		{
			perror("execution failed");
		}
	}

}
