/****************************
 * Cameron Kimner
 * ckimner@clemson.edu
 * 10/25/2020
 * CPSC 1020, Section 1, Programming Assignment 1
 * Kittelstad 
 * *************************/
#include "dll_list.h"

using namespace std;

int main(int argc, char* argv[]){
    ifstream inFile(argv[1]);
    list_t * animalList = newList();

    bool haveInitFromFile = false;
    bool loopControl = true;
    string deleteIn;
    int menuChoice;
    while(loopControl){
        //gets input for menu and checks if valid
        do{
            menuChoice = printMenu();
            if(menuChoice < 1 || menuChoice > 9){
                cout << "Error: input is not a menu choice" << endl;
            }
        }while(menuChoice < 1 || menuChoice > 9);

        switch(menuChoice){
            //initialize list of animals from text file
            case 1:
                if(!haveInitFromFile){
                    initializeFromFile(animalList, inFile);
                    haveInitFromFile = true;
                }else{
                    cout << "** List is already initialized **" << endl;
                }
                break;
            //Add animal to front of list
            case 2:
                addToFront(animalList);
                break;
            //Add animal to the end of list
            case 3:
                addToRear(animalList);
                break;
            //Delete animal from list
            case 4:
                cout << "Enter name of animal you wish to delete: " << endl;
                cin >> deleteIn;
                deleteAnimal(animalList, deleteIn);
                break;
            //Search animals by type
            case 5:
                searchByType(animalList);
                break;
            //Search animals by name
            case 6:
                searchByName(animalList);
                break;
            //Show number of animals in the list
            case 7:
                cout << "There are " << size(animalList) <<
                     " animals in the list" << endl;
                break;
            //Print animals in the list
            case 8:
                printList(animalList);
                break;
            //Close program
            case 9:
                cout << "Closing program now" << endl;
                //sets loop to false to exit function
                loopControl = false;
                break;
        }
    }
    //closing input file
    inFile.close();
    //free memory from linked list
    freeList(animalList);
    //main return statement
    return 0;
}