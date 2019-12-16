#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void printDir(){
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDirectory: %s", cwd);
}

char ** parse_args( char * line ){
  char * curr = line;
  char ** args = malloc(100);
  const char *delimiters = " \t\n";
  int x;
  for (x = 0; curr != NULL; x++){
    args[x] = strsep (&curr, delimiters);
  }
  return args;
}

void execArgs(char ** args){
	int pid = fork();
	if (pid == -1){
		printf("\n Failed Fork")
	}
	elseif (pid == 0){
		execvp(args[0], args)
	}
	else{
		wait(NULL);
	}
	return;
}
	
int main(){
	char input[512];
	char ** args;
	while (1){
		printDir();
		fgets(input, 512, stdin);
		input[strlen(input)-1] = 0;
		args = parse_args(input);
		execArgs(args);
	}
}