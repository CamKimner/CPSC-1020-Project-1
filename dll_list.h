/****************************
 * Cameron Kimner
 * ckimner@clemson.edu
 * 10/25/2020
 * CPSC 1020, Section 1, Programming Assignment 1
 * Kittelstad 
 * *************************/

#ifndef DLL_LIST_H
#define DLL_LIST_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct animal {
	string aType;
	string aName;
	struct animal *prev;
	struct animal *next;
} animal_t;


typedef struct list {
	animal_t *head;
	animal_t *tail;
	int size;
} list_t;

int printMenu( );  
void menuControl();
list_t *newList( );
void listInit( list_t *list, ifstream &inFile  );
void initializeFromFile( list_t *list, ifstream &inFile  );
animal_t *newAnimal( ifstream &inFile );
void addToFront( list_t *list );
void addToRear( list_t *list );
void deleteAnimal( list_t *list, string animalName );
void searchByType( list_t *list );
void searchByName( list_t *list );
int isEmpty( list_t *list );
int size( list_t *list );
void printList ( list_t *list );
void freeList(list_t *list);


#endif /* DLL_LIST_H */
