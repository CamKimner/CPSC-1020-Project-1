/****************************
 * Cameron Kimner
 * ckimner@clemson.edu
 * 10/25/2020
 * CPSC 1020, Section 1, Programming Assignment 1
 * Kittelstad 
 * *************************/

#include "dll_list.h"

using namespace std;

//prints menu of choices for use to chose from, return choice int
int printMenu( ){
    int option;

    cout << endl << "1. Initialize list of animals from a file" << endl;
    cout << "2. Add an animal to the front of the list" << endl;
    cout << "3. Add an animal to the end of the list" << endl;
    cout << "4. Delete an animal from the list" << endl;
    cout << "5. Search animals by type" << endl;
    cout << "6. Search animals by name" << endl;
    cout << "7. Show number of animals in list" << endl;
    cout << "8. Print animals in the list" << endl;
    cout << "9. Close program" << endl << endl;
    cout << "Please enter the number of desired function: " << endl;

    cin >> option;
    
    return option;
}

// creates a new list; initializes size and head & tail
// pointers; returns a pointer to the new list
list_t *newList( ){
    list_t * animals = new list_t;

    animals->head = nullptr;
    animals->tail = nullptr;
    animals->size = 0;
    return animals;
}

// called from initializeFromFile(); call newAnimal() to create and initialize
// a new animal from the file; then add it to the end of the list
// increments the list size for each animal added
void listInit( list_t *list, ifstream &inFile  ){
    animal_t * tempAnimal = newAnimal(inFile);

    tempAnimal->next = nullptr;
    if(isEmpty(list) == 1){
        tempAnimal->prev = nullptr;
        list->head = tempAnimal;
        list->tail = tempAnimal;
    }else{
        list->tail->next = tempAnimal;
	    tempAnimal->prev = list->tail;
        list->tail = tempAnimal;
    }

    list->size ++;
}

// calls listInit() sending the input file pointer (which is the file
// specified at the command-line)
// note – the first value in the input file is the number of animals in the
// file – that will be the first value read in from the file so you
// know how many times the loop needs to go
void initializeFromFile( list_t *list, ifstream &inFile  ){
    int numFromFile;
    inFile >> numFromFile;

    for(int i = 0; i < numFromFile; i++){
        listInit(list, inFile);
    }
}

// called by listInit() function
// creates and initializes a new animal node from the input file pointer
// sent in
// returns a pointer to the animal that was just created
animal_t *newAnimal( ifstream &inFile ){
    animal_t * newestAnimal = new animal_t;
    inFile >> newestAnimal->aType;
    inFile >> newestAnimal->aName;
    
    return newestAnimal;
}

// creates a new animal from user input and then adds it to the front of
// the list; should use the head pointer
// increments the list size
void addToFront( list_t *list ){
    animal_t * tempAnimal = new animal_t;
    //user I/O for new animal
    cout << "Please enter the new animal's type: " << endl;
    cin >> tempAnimal->aType;
    cout << "Please enter the new animal's name: " << endl;
    cin >> tempAnimal->aName;

    tempAnimal->next = list->head;
    tempAnimal->prev = nullptr;
    if(isEmpty(list) == 0){
        list->head->prev = tempAnimal;
    }
    list->head = tempAnimal;
    //increments list size after new node is added
    list->size ++;
}

// creates a new animal from user input and then adds it to the rear of
// the list; should use the tail pointer
// increments the list size
void addToRear( list_t *list ){
    animal_t * newAnimal = new animal_t;
    //user I/O for new animal
    cout << "Please enter new animal type: " << endl;
    cin >> newAnimal->aType;
    cout << "Please enter new animal name: " << endl;
    cin >> newAnimal->aName;

    newAnimal->next = nullptr;
    if(isEmpty(list) == 1){
        newAnimal->prev = nullptr;
        list->head = newAnimal;
        list->tail = newAnimal;
    }else{
        list->tail->next = newAnimal;
	    newAnimal->prev = list->tail;
        list->tail = newAnimal;
    }
    //increments size variable after new node is added
    list->size ++;
}

// deletes the animal with the aName that matches the parameter animalName;
// decrements the list size
// if list is empty, prints message that the list is empty
void deleteAnimal( list_t *list, string animalName ){
    //checks if list is empty first
    if(isEmpty(list) == 1){
        cout << "No animals currently in list, cannot delete" << endl;
        //exits function if empty
        return;
    }
    //variables
    bool foundAnimal = false;
    animal_t * current = list->head;
    animal_t * tempPrev;
    animal_t * tempNext;
    //loop through linked list
    for(int i = 0; i < list->size; i++){
        if((current->aName).compare(animalName) == 0){
            //deleting node and setting surrounding nodes
            tempPrev = current->prev;
            tempNext = current->next;
            delete current;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;

            foundAnimal = true;
            list->size --;
        }
        //increment to next node
        current = current->next;
    }
    //if no animals of the input name are found
    if(!foundAnimal){
        cout << "No " << animalName << "s were found in the list" << endl;
    }
}

// searches the list for aType and returns all found, or message that no
// animals of that type were found
void searchByType( list_t *list ){
    string inType;
    cout << "What is the type of the animal you are looking for? " << endl;
    cin >> inType;

    //loop variables
    animal_t * current = list->head;
    bool foundAnimal = false;
    //loop through linked list
    for(int i = 1; i <= list->size; i++){
        //prints when animal type is found
        if((current->aType).compare(inType) == 0){
            cout << current->aType << "  " << current->aName << " is number " <<
                i << " in the list" << endl;
            foundAnimal = true;
        }
        current = current->next;
    }
    //prints if animal was not found
    if(!foundAnimal){
        cout << "No " << inType << "s were found in the list" << endl;
    }
}

// searches the list for aName and returns all found, or message that no
// animals of that type name were found
void searchByName( list_t *list ){
    //gets animal name from user I/O
    string inName;
    cout << "What is the name of the animal you are looking for? " << endl;
    cin >> inName;

    //loop variables
    animal_t * current = list->head;
    bool foundAnimal = false;
    //loop through linked list
    for(int i = 1; i <= list->size; i++){
        //prints when animal name is found
        if((current->aName).compare(inName) == 0){
            cout << current->aType << "  " << current->aName << " is number " <<
                i << " in the list" << endl;
            foundAnimal = true;
        }
        current = current->next;
    }
    //prints if animal was not found
    if(!foundAnimal){
        cout << "No " << inName << "s were found in the list" << endl;
    }
}

// returns 1 if the list is empty and 0 if it is not empty; may be used in
// other functions
int isEmpty( list_t *list ){
    if ((list->head == nullptr) && (list->tail == nullptr)){
        return 1;
    } else{
        return 0;
    }
}

// returns the size of the list; may be used in other functions
int size( list_t *list ){
    int sizeCount = 0;
    animal_t * current = list->head;

    while(current != NULL){
        current = current->next;
        sizeCount ++;
    }

    return sizeCount;
}

//prints animals currently in list, requires list of animals as parameter
void printList ( list_t *list ){
    animal_t * current = list->head;

    cout << "Animals in list: " << endl << endl;
    while(current != nullptr){
        cout << current->aType << "  ";
        cout << current->aName << endl;
        current = current->next;
    }
}

//frees memory from linked list, takes in list as parameter
void freeList(list_t *list){
    animal_t * current = list-> head;
    animal_t * nextFree;

    cout << "Freeing list memory" << endl;
    while(current != nullptr){
        nextFree = current->next;
        delete current;
        current = nextFree;
    }
}