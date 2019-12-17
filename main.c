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

char * remove_spaces(char * input){
	if (input[0] == 32) {
		input++;
	}
	if (input[strlen(input) - 1] == 32){
		input[strlen(input) - 1] = 0;
	}
	return input;
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

void execPipedArgs(char** args, char** parsedargs) { 
    int fds[2];  
    int pid1, pid2; 
	int READ = 0;
	int WRITE = 1;
  
    if (pipe(fds) < 0){ 
        printf("\nPipe failed"); 
    }
    pid1 = fork();
    if (pid1 < 0){ 
        printf("\n Failed Fork"); 
    } 
    if (pid1 == 0){ 
        close(fds[READ]); 
        dup2(fds[WRITE], STDOUT_FILENO); 
        close(fds[WRITE]); 
		execvp(args[0], args);
    } 
	else{ 
        pid2 = fork(); 
        if (pid2 < 0){ 
            printf("\nFailed Fork"); 
        } 
        if (pid2 == 0){ 
            close(fds[WRITE]); 
            dup2(fds[READ], STDIN_FILENO); 
            close(fds[READ]); 
            execvp(parsedargs[0], args);
        } 
		else{ 
			wait(NULL); 
            wait(NULL); 
        } 
    } 
}

int main(){
	char input[512];
	char ** args;
	char ** cmds;
	while (1){
		printDir();
		fgets(input, 512, stdin);
		input[strlen(input) - 1] = 0;
		cmds = parse(input, ";");
		int i;
		for (i = 0; cmds[i] != NULL; i ++){
			printf("\n%s",cmds[i]);
			cmds[i] = remove_spaces(cmds[i]);
			args = parse(cmds[i], "-");
			execArgs(args);
		}
	}
}