// Alen Ovalles
// hw3.cpp
// Purpose: Creating a linked list, append integers, reverse list 
//          and delete a node at a given index 
//
// Input: User input integers and menu details, has to create a list before anything else
// Processing: Users choice in 1-2-3-4-5, does diffferent choices/outcomes
// Output: 1) None, 2) Displays list, 3) Reverse and displays list, 4) Deletes a node, 5) Dealocate list
//
// Example: Menu choice: 1 
//          Input values for list: 1 2 3 4
//
//          Menu choice: 2
//          List is: 1 2 3 4 
//
//          Menu choice: 3 
//          Reverse list is now: 4 3 2 1 
//
//          Menu choice: 4
//          Delete n-th node of 2
//          List is now: 4 3 1
//
//          Menu choice: 4
//          Delete n-th node of 3
//          List is now: 3 1 
//
//          Menu choice: 3 
//          Reverse list is now: 1 3
//
//          Menu choice: 5  
//          Dealocating...
//          Deleting 1
//          Deleting 3
//

#include "FancyList.h"
#include <iostream>
using namespace std;

void printMenu(int & choice);
// Prints the FancyList Menu

void appendList(FancyList & list, int & counter);
// Asks user for input until entered 'x'

void validNode(int counter, int & node);
// Checks if the entered node is valid

int main(){ 
    int choice, counter = 0;
    bool created = false;
    FancyList list; 

    cout << endl;
    printMenu(choice);

    while(choice != 5){
        if(choice != 1 && created == false){ // IF LIST ISN'T CREATED
            cout << "List has not been created" << endl;
            cout << "Please select option 1 to create list before any adjustments" << endl;
            cout << endl;
        }
        else if(choice == 1 && created == false){ // APPENDS USER'S INPUT INTO LIST
            appendList(list, counter);
            created = true;
        }
        else if(choice == 1 && created == true){ // IF LIST IS ALREADY CREATED WITH AT LEAST ONE NODE
            cout << "List has already been created" << endl;
            cout << endl;
        }
        else if(choice == 2){ // DISPLAYS LIST
            cout << "Current list is: ";
            list.displayList();
        }
        else if(choice == 3){ // REVERSE LIST
            cout << "Current list after reversing is: ";
            list.reverse();
            list.displayList();
        }
        else if(choice == 4){ // DELETE N-TH NODE 
            int num;

            cout << "Delete n-th node from the end of the list, your n is: ";
            cin >> num;

            validNode(counter, num);
            list.deleteNode(counter, num);

            cout << "Current list after deleting the " << num << "-th node from the end is: ";
            list.displayList();
        }
        printMenu(choice);
    }
    return 0;
}

void printMenu(int & choice){
    cout << "********* FancyList Menu *********" << endl;
    cout << "1. Create a list" << endl;
    cout << "2. Display the list" << endl;
    cout << "3. Reverse the list" << endl;
    cout << "4. Delete the n-th node from the end of the list" << endl;
    cout << "5. Exit the program" << endl << endl; 

    cout << "Enter your choice: ";
    cin >> choice;
}

void appendList(FancyList & list, int & counter){
    int num;
    while(counter == 0){
        while(!cin.fail()){
            cout << "Type a number for appending (type x to stop): ";
            cin >> num;
            if(!cin.fail()){
                list.append(num);
                counter++;
            }
        }   
        cin.clear(); 
        cin.ignore();
        if(counter == 0){
            cout << "Please enter at least one integer into the list to move on" << endl;
            cout << endl;
        }
    }
    cout << endl;
}

void validNode(int counter, int & node){
    while(node > counter || node < 0){
        cout << endl;
        cout << "n-th node isn't in the list, enter a different node" << endl;
        cout << "Delete n-th node from the end of the list, your n is: ";
        cin >> node;
    }
}