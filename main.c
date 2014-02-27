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
//commandMap map[] = {
//  {"-p", printLines},
//  {"-s", sort},
//=======
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



// our array that tells how command-strings map t
void convert(char **a) {
  int i,j;
  for (i=0;a[i]!=NULL;i++){
    for(j=0;a[i][j]!='\0';j++){
      if(isalpha(a[i][j])&&islower(a[i][j])){
        a[i][j]-=32;
      }
    }
  }
}
void reverseChars(char **a){
  int i,j,count=0;
  char tempChar;
  if(a[0][2]=='\0'){
    return;
  }
  for (i=0;a[i]!=NULL;i++){
    for(j=0;a[i][j]!='\0';j++){
      count++;
    }
  }
  count--;
  for(i=0;a[i]!=NULL;i++){
    for(j=0;j<count;j++,count--){
      tempChar = a[i][count];
      a[i][count]=a[i][j];
      a[i][j]=tempChar;      
    }
  }
}
// our array that tells how command-strings map to functions
commandMap map[] = {
  {"-p", printLines},{"-u",convert},{"-rr",reverseChars},{"-e", encryptLines},{"-d",decryptLines},{"-r",reverse},{"-s",sort},
  //>>>>>>> eaf0cbd2c2b2039b2d03b33185e1d3ff5d909bc5
  //>>>>>>> 8c41f8c42ed8db89c60ddb7c8523cba0b2284f68
//>>>>>>> c9f6c550bf6f1b6c0d3fa83239c5bd40c10807cd
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
