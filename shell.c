#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  char input[100];
  if (argc > 0){
    fgets(input,100,stdin);
    input[strlen(input)-1] = 0;
  }
  int READ = 0;
  int WRITE = 1;
  int fds[2];
  pipe(fds);
  int f = fork();
  if (f == 0){
    close(fds[WRITE]);
    read(fds[READ], input, sizeof(input));
    char ** args = parse_args(input);
    execvp(args[0], args);
  }
  else{
    close(fds[READ]);
    write(fds[WRITE], input, sizeof(input));
  }
  return 0;
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
