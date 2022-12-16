#include "main.h"
/**
  *
  *
  *
  */

char *path(char *command)
{
	char *path, *path_cpy, *path_token, *file_path;
	int cm_len, length;

	path = getenv("PATH");
	path_cpy = strdup(path);

	cm_len = strlen(command);
	path_token = strtok(path_cpy, ":");
	length = strlen(path_token);
	file_path = malloc(cm_len + length + 2);

}
