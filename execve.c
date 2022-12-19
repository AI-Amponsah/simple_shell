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
	pid_t pid;

	if (argv)
	{
		command = argv[0];
		real_command = find_path(command);
		pid = fork();
		if (pid == -1)
		{
			perror("Failed");
			return;
		}
		else if (pid == 0)
		{
			if (execve(real_command, argv, NULL) == -1)
			{
				perror("execution failed");
			}
		}
		else
		{
			wait(NULL);
			return;
		}
	}

}
