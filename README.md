Shell
by Jason Zheng

Features:
	Forks and executes commands!
	Parses multiple commands on one line!

Attempted:
	The following did not end up working, but have been left in the code, commented out.
	Could not get pipes to work
	
Files & Function Headers:
main.c

	/*======== void printDir() ==========
	Inputs:  N/A
	Returns: N/A

	Prints current directory
	====================*/

	/*======== char * remove_spaces() ==========
	Inputs:  char *input
	Returns: Pointer to the beginning of input

	Removes leading and trailing whitespace on the string line.
	Terminating '\0' is placed at a new location if necessary.
	====================*/
  
  	/*======== char ** parse() ==========
	Inputs:  char *line char *delimiter
	Returns: Double pointer to the beginning of the parsed line

	Uses remove_spaces()
  Parse on delimiters
	====================*/
  
  	/*======== void execArgs() ==========
	Inputs:  char ** args 
	Returns: N/A

	Fork
  Parent waits for child to finish executing args
	====================*/
