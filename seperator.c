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

  ///struct Word* toReturn = (struct Word*)malloc(sizeof(struct Word));
}

struct Word createWord(struct Word word, char* line) {
  if (line == NULL) {
    return word;
  }

  int index = 0;  
  char* charRun = line;
  
  while (charRun[index] != '\0' && charRun[index] != ',') {
    charRun++;
    index++;
  }
  
  if (charRun[index] != ',') {
    struct Word word = (struct Word*)malloc(sizeof(struct Word));
    word->textPtr_ = charRun++;
    
  }
  
  if (charRun[index] != '\0') {
    return word;
  }
  return createWord(line + 1);
}

