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

void reverse(char** a)
{
  int i;
  int k = 0;
  char* temp;
  //char* temp2;
for (i = 0; a[i] != NULL; i++) {
  k++;
  }

 for(i = 0, k--;i<k ;i++,k--)
  {
    
      temp = a[k];
      a[k] = a[i];
      a[i] = temp;

    
    
   
  }
}

// our array that tells how command-strings map to functions
commandMap map[] = {
  {"-p", printLines},
  {"-r", reverse},
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
