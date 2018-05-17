#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int NUM_CHAR = 100;

struct Word {
  char*		textPtr_;
  struct Word*	nextPtr_;
};

int main(int argc, char* argv[]) {
  printf("Enter a comma-seperated list of strings:\n");

  char* line;
  fgets(line, NUM_CHAR, stdin); 
  
  char*	cPtr = strchr(line,'\n');
  if  (cPtr != NULL) {
    *cPtr = '\0';
  }

  struct Word* toReturn = (struct Word*)malloc(sizeof(struct Word));
}
