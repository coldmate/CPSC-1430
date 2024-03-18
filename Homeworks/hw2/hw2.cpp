// Alen Ovalles
// hw2.cpp
// Purpose: Writing a Class
// Input: User inputs elements into the given set
// Processing: Stores user's input in given set, creates new objects for union and intersetion
// Output: Display the following outputs from the given member functions, ie, printSet, unionOfSet...
// Example: 45 76 34 6 x 34 8 93 45 x 77
//
//          Set A is now:
//          { 6 34 45 76 }
//          
//          Set B is now:
//          {8 34 45 93}
//
//          Union of Set A and B
//          { 6 8 34 45 76 93 }
//
//          Intersetion of Set A and B
//          { 34 45 }
//
//          Enter element to add to set A: 77
//          Set A is now:
//          { 8 34 45 76 77 }
//
//          Deleting element 
//          Set A is now:
//          { 8 34 45 76 }

#include <iostream>
#include "IntegerSet.h"
using namespace std;

const int C_SIZE = 10;

void declareUnionSet(IntegerSet setA, IntegerSet setB);
// Creates new object (unionSet)
// Prints out unionSet; combination of elements in set A and B

void declareIntersetionSet(IntegerSet setA, IntegerSet setB);
// Creates new object (intersetionSet)
// Prints out intersetionSet; combination of elements that 
// are both in set A and B

void setEqualTo(IntegerSet setA, IntegerSet setB, int & input);
// Checks if both of the sets are equal in elements
// Asks for user to add another element to set A

void deleteIndex(IntegerSet setA, int input);
// Deletes the previous added element in set A

void declareSetC(int arr[]);
// Creates new object (setC) 
// Calls the second constructor
// Prints out setC

int main(int argc, char *argv[]){
    int input;
    int arr[10] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1}; // Hardcoded array

    cout << endl;

    // DECLARING SET A
    IntegerSet setA;
    cout << "Enter set A: " << endl;
    setA.inputSet();

    // DECLARING SET B
    IntegerSet setB;
    cout << "Enter set B: " << endl;
    setB.inputSet();

    // DECLARING UNION SET
    declareUnionSet(setA, setB);

    // DECLARING INTERSETION SET
    declareIntersetionSet(setA, setB);

    // CHECKS IF SET A IS EQUAL TO SET B
    setEqualTo(setA, setB, input);

    // DELETES USER ELEMENT
    deleteIndex(setA, input);

    // DECLARE SET C | HARDCODED
    declareSetC(arr);

    return 0;
}

void declareUnionSet(IntegerSet setA, IntegerSet setB){
    IntegerSet unionSet = setA.unionOfSets(setB);
    cout << "Union of A and B is:" << endl;
    unionSet.printSet();
}

void declareIntersetionSet(IntegerSet setA, IntegerSet setB){
    IntegerSet intersetion = setA.intersetionOfSets(setB);
    cout << "Intersection of A and B is:" << endl;
    intersetion.printSet();
}   

void setEqualTo(IntegerSet setA, IntegerSet setB, int & input){
    if(setA.isEqualTo(setB)){
        cout << "Set A is equal to set B" << endl;
    }
    else{
        cout << "Set A is not equal to set B" << endl;
    }
    cout << "What element would you like to insert into set A?: ";
    cin >> input;
    cout << endl;
    cout << "Set A is now: " << endl; 
    setA.insertElement(input);
    setA.printSet();
}

void deleteIndex(IntegerSet setA, int input){
    setA.deleteElement(input);
    cout << "Deleting " << input << " from set A..." << endl;
    cout << "Set A is now: " << endl;
    setA.printSet();
}

void declareSetC(int arr[]){
    cout << "Now creating a set of specific values and testing the bounds limits." << endl;
    cout << "Creating array of size 10: {25, 67, 2, 9, 99, 105, 45, -5, 100, 1} " << endl;
    cout << "(Note from instructor: hardcode this array in your program)" << endl;

    IntegerSet setC(arr, C_SIZE);
    cout << endl;

    cout << "Set C is: " << endl;
    setC.printSet();
}