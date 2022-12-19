#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
void exe_cute(char **argv);
char *find_path(char *command);
#endif
