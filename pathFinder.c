#include "main.h"
/**
  *find_path - path finder function
  *@command: command parameter
  *Return: NULL.
  */

char *find_path(char *command)
{
	char *path, *path_cpy, *path_token, *file_path;
	int cm_len, length;
	struct stat buf;

	path = getenv("PATH");
	if  (path)
	{
		path_cpy = strdup(path);
		cm_len = strlen(command);
		path_token = strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			length = strlen(path_token);
			file_path = malloc(cm_len + length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buf) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);

}
