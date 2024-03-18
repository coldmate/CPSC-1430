// Alen Ovalles
// lab6.cpp
// Purpose: Writing a Linked List
// Input: User input integers
// Processing: Inserts user inputs into linked list, creates and copies listA to listB
// Output: Prints and deletes linked list
//
// Example: 
//          Type a integer to be inserted into List A: 4
//          Type a integer to be inserted into List A: x
//
//          List A is: 4
//          List B is copied from List A: 4
//
//          Type a integer to be inserted into List B: 7
//          Type a integer to be inserted into List B: x
//
//          List A is: 4
//          List B now is: 4 7
//
//          Deallocating...
//          Deleting 4
//          Deleting 7 
//
//          Deallocating...
//          Deleting 4

#include "OrderedList.h"
#include <iostream>
using namespace std;

void inputList(OrderedList & list);
// Asks user for integers, to be inserts to list

int main(){
    OrderedList listA;

    cout << endl;
    cout << "Asking user to type and create listA..." << endl << endl;
 
    inputList(listA); // Asks user to input values for listA
    cout << "listA is: ";
    listA.printList();

    OrderedList listB(listA); // Calls copy constructor

    cout << "listB is copied from List A: ";
    listB.printList();
    cout << endl;

    cout << "Asking user to type and add more to listB..." << endl << endl;
    inputList(listB); // Asks user to add values to listB

    cout << "listA is: ";
    listA.printList();
    cout << "listB now is: ";
    listB.printList();
    cout << endl;

    return 0;
}

void inputList(OrderedList & list){
    int num;
    while(!cin.fail()){
        cout << "Type a number for insertion (type x to stop): ";
        cin >> num;
        if(!cin.fail()){
            list.insert(num); 
            cout << endl;
        }
    }
    cin.clear();
    cin.ignore();

    cout << endl << endl;
}