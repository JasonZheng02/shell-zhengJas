#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * parse_args( char * line ){
  char * args[5];
  char * curr = line;
  int x;
  for (x=0; curr != NULL; x++){
    args[x] = strsep (&curr, " ");
  }
  return args;
}
int main(int argc, char *argv[]) {
  char* input = malloc(100);
  if (argc > 0){
    fgets(input,100,stdin);
    input[strlen(input)-1] = 0;
  }
  char ** args = parse_args(input);
  printf("%s\n", args);
  return 0;
}
