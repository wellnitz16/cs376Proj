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

//encrypt each line with algorithm; printable chars, 33 thru 126 are rotated
void encryptLines(char** a){
  int i,p;
  for (i = 0; a[i] != NULL; i++)
    {
      for (p = 0; a[i][p] != '\0'; p++){
	if (a[i][p] == 126){
	  a[i][p] = 33;
	}
	else {
	  a[i][p] = a[i][p] + 1; 
	}
      }
     }
}

//decrypt each line from encryptLines algorithm
void decryptLines(char** a){
  int i,p;
  for (i = 0; a[i] != NULL; i++){
    for (p = 0; a[i][p] != '\0'; p++){
      if (a[i][p] == 32){
	a[i][p] = 126; 
      }
      else {
	a[i][p] = a[i][p] -1; 
      }
    }
  }

}



// our array that tells how command-strings map to functions
commandMap map[] = {
  {"-p", printLines},
  {"-e", encryptLines},
  {"-d", decryptLines},
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
