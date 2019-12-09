#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char ** parse_args( char * line ){
  char * curr = line;
  char ** args = malloc(100);
  int x;
  for (x = 0; curr != NULL; x++){
    args[x] = strsep (&curr, " ");
  }
  return args;
}

int main(int argc, char *argv[]) {
  char input[100];
  if (argc > 0){
    fgets(input,100,stdin);
    input[strlen(input)-1] = 0;
  }
  printf("%s\n", input);
  char ** args = parse_args(input);
  execvp(args[0], args);
  return 0;
}
