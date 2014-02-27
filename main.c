#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "readLine.h"
#include "execCmds.h"

// print the elements in the array, up to (but not including) the first
// NULL entry
void printLines(char** a) {
  int i;
  for (i = 0; a[i] != NULL; i++) {
	printf("%s\n", a[i]);
  }
}

void sort(char ** a) // The worst function you'll ever see.
{
	int i;
	int j;
	int k=0;
  	char * placeHolder;
  	char ** original;
	int total = 0; 
 	int sorted = 0;
	
	for (i = 0; a[i + 1] != NULL; i++)
	{
		k++;
	}

	for (j = 0; a[j] != NULL; j++) 
	{

  		while (sorted != 1)
  		{
    			original = a;
    			for (i = 0; a[i] != NULL; i++) 
			{
	      			if (a[i + 1] != NULL)
				{
					total++;
					if (strcmp(a[i],a[i+1]) > 0)
					{
    						placeHolder = a[i + 1];
						a[i + 1] = a[i];
						a[i] = placeHolder;
		      				total--;
					}
				}
    			}
	
			if (a == original)
    			{
      				sorted = 1;
    			}
  		 }
	}

	if (total != k) sort(a);
}

// our array that tells how command-strings map to functions
commandMap map[] = {
  {"-p", printLines},
  {"-s", sort},
  {NULL, NULL},
};

// main function
int main(int argc, char* argv[]) {
  // read lines from standard input
  char** lines = readLines();

  // execute each command on the command line
  executeCommands(lines, map, argv+1);

  // exit with "success"
  return EXIT_SUCCESS;
}
