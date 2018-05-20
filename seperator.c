#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int NUM_CHAR = 256;

struct Word {
  char*		textPtr_;
  struct Word*	nextPtr_;
};

char* getFirstWord(const char* string) {
  int index = 0;  
  
  while (string[index] != '\0' && string[index] != ',') {
    index++;
  }

  if (string[index] == ',' || (string[index] == '\0' && index != 0)) {
    char* firstWord = (char*)malloc(sizeof(index+1));
    size_t nToCopy = index;
    strncpy(firstWord, string, nToCopy);
    return firstWord;
  }
  
  if (string[index] == '\0') {
    return "\0";
  }
}

struct Word* obtainCommaSeparatedList(const char* string) {
  struct Word* toReturn = (struct Word*)malloc(sizeof(struct Word));
  char* firstWord = getFirstWord(string);
  toReturn->textPtr_ = firstWord;

  int firstWordSize = strlen(firstWord);
  int stringSize = strlen(string);
  
  if (firstWordSize == 0 && stringSize == 0 || stringSize == firstWordSize) {
    return toReturn;
  }

  char* stringCopy = (char*)malloc(stringSize + 1);
  strncpy(stringCopy, string, stringSize); 

  char* remainingString = &(stringCopy[firstWordSize + 1]);
  toReturn->nextPtr_ = obtainCommaSeparatedList(remainingString);

  return toReturn;
}

void printCommaSeparatedList(const struct Word* list) {
  printf("\"%s\"\n", list->textPtr_);
  if (list->nextPtr_ != NULL) {
    printCommaSeparatedList(list->nextPtr_);
  }
}

void freeCommaSeparatedList(struct Word* list) {
  if (list->nextPtr_ != NULL) {
    freeCommaSeparatedList(list->nextPtr_); 
  } 
  free(list);
}

int main(int argc, char* argv[]) {
  printf("Enter a comma-seperated list of strings:\n");

  char line[NUM_CHAR];
  fgets(line, NUM_CHAR, stdin); 
  
  char*	cPtr = strchr(line,'\n');
  if  (cPtr != NULL) {
    *cPtr = '\0';
  }

  struct Word* wordList = obtainCommaSeparatedList(line);
  printCommaSeparatedList(wordList);
  freeCommaSeparatedList(wordList);

  return(EXIT_SUCCESS);
}


