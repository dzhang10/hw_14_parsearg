#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *command[5];

char ** parse_args(char * line){
	char **args = command;
	char *token;
	char *p;
	p = line;
	int counter = 0;
	while(p){
		token = strsep(&p," ");
		args[counter] = token;
		counter++;
	}
	args[counter] = NULL;
	return command;
}


int main(){
	char line[] = "ls -a -l";
	char ** args = parse_args(line);
	execvp(args[0],args);
	return 0;
}
