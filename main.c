#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void printDir(){
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDirectory: %s ", cwd);
}

char ** parse( char * line, char * delimiter){
  char * curr = line;
  char ** args = malloc(100);
  int x;
  for (x = 0; curr != NULL; x++){
    args[x] = strsep (&curr, delimiter);
  }
  return args;
}

void execArgs(char ** args){
	int pid = fork();
	if (pid == -1){
		printf("\n Failed Fork");
	}
	else if (pid == 0){
		execvp(args[0], args);
	}
	else{
		wait(NULL);
	}
	return;
}
	
int main(){
	char input[512];
	char ** args;
	char ** cmds;
	while (1){
		printDir();
		fgets(input, 512, stdin);
		input[strlen(input)-1] = 0;
		cmds = parse(input, ";");
		int i;
		for (i = 0; cmds[i] != NULL; i ++){
			args = parse(cmds[i], "");
			execArgs(args);
		}
	}
}