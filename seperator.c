#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int NUM_CHAR = 100;

struct Word {
  char*		textPtr_;
  struct Word*	nextPtr_;
};

char* getFirstWord(const char* string) {
  int index = 0;  
  
  while (string[index] != '\0' && string[index] != ',') {
//    printf("char at index %d: %c\n", index, string[index]);
    index++;
  }

  if (string[index] == ',' || (string[index] == '\0' && index != 0)) {
    char* firstWord = (char*)malloc(sizeof(index+1));;
    size_t nToCopy = index;
    strncpy(firstWord, string, nToCopy);
    return firstWord;
  }
  
  if (string[index] == '\0') {
    return "\0";
  }
}

struct Word* obtainCommaSeparatedList(const char* string) {
  printf("String: %s\n", string);
  struct Word* toReturn = (struct Word*)malloc(sizeof(struct Word));
  char* firstWord = getFirstWord(string);
  printf("First word: %s\n", firstWord);
  toReturn->textPtr_ = firstWord;
  int firstWordSize = strlen(firstWord);
  int stringSize = strlen(string);
  printf("firstWordSize: %d\n", firstWordSize);
  printf("string size: %d\n", stringSize);
  if (firstWordSize == 0 && stringSize == 0 || stringSize == firstWordSize) {
  // TODO  free(firstWord);
    return toReturn;
  }
  char stringCopy[stringSize];
  strncpy(stringCopy, string, stringSize); 
  char* remainingString = &(stringCopy[firstWordSize + 1]);
  printf("Remaining string: %s\n", remainingString);
  toReturn->nextPtr_ = obtainCommaSeparatedList(remainingString);
 // TODO free(firstWord);
  return toReturn;
}

void printCommaSeparatedList(const struct Word* list) {
  printf("\"%s\"\n", list->textPtr_);
  if (list->nextPtr_ != NULL) {
    printCommaSeparatedList(list->nextPtr_);
  }
}

void freeCommaSeparatedList(struct Word* list) {
 // Word current = list;
 // while (current->nextPtr_ != NULL) {
 //   free()
 // }
}

int main(int argc, char* argv[]) {
  printf("Enter a comma-seperated list of strings:\n");

  char line[NUM_CHAR];
  fgets(line, NUM_CHAR, stdin); 
  
  char*	cPtr = strchr(line,'\n');
  if  (cPtr != NULL) {
    *cPtr = '\0';
  }

  printf("Line: %s\n", line);
//  char* firstWord = getFirstWord(line);
//  printf("First word: %s\n", firstWord);

  struct Word* wordList = obtainCommaSeparatedList(line);
  printCommaSeparatedList(wordList);
//  freeCommaSeparatedList(wordList);

  return(EXIT_SUCCESS);
}




/*
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
*/



