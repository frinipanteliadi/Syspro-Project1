#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

/*********************/
/*** MAP FUNCTIONS ***/
/*********************/

/* Parses the texts from the file into the map */
void initializeMap(FILE* fp, char* line, char* delimiter,map* array){
	size_t n = 0;
	int i = 0;
	while(getline(&line,&n,fp)!=-1){
		char *id;
		id = strtok(line," ");
		array[i].id = atoi(id);
		char *text = strtok(NULL,"\n");
		array[i].text = (char*)malloc(strlen(text)+1);
		strcpy(array[i].text,text);
		i++;
	}
}

void printMap(int lines, map* ptr){
	for(int i = 0; i < lines; i++){
		printf("-----------------------\n");
		printf(" *ID: %d\n",ptr[i].id);
		printf(" *TEXT: %s\n",ptr[i].text);
		printf("-----------------------\n");
	}
}

/***************************/
/*** TRIE ROOT FUNCTIONS ***/
/***************************/

/* Initializes all of the root's members */
void initializeRoot(trieNode **root){

	(**root).letter = 0;
	(**root).isEndOfWord = False;
	// (**root).listPtr = NULL;
	(**root).arraySize = 0;
	(**root).childNodes = 0;
	(**root).children = NULL;
}

/* Prints the values of the root's members */
void printRoot(trieNode **root){
	printf("ROOTS INFORMATION:\n");
	printf(" *Letter: %d\n",(**root).letter);
	printf(" *IsEndOfWord: %d\n",(**root).isEndOfWord);
	printf(" *ArraySize: %d\n",(**root).arraySize);
	printf(" *ChildNodes: %d\n",(**root).childNodes);
	printf(" *Children: %s\n",(**root).children);
}

/**********************/
/*** FILE FUNCTIONS ***/
/**********************/
int getNumberOfLines(FILE* fp, char* lineptr){
	size_t n = 0;
	int lines = 0;
	while(getline(&lineptr,&n,fp)!=-1){
		lines++;
	}
	return lines;
}
