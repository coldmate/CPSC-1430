// Alen Ovalles
// hw2.cpp
// Purpose: Writing a Class; the main function section
// Input: User inputs numbers
// Processing: Stores user's input in a set 
// Output: Display the following outputs from the given member functions

#include <iostream>
#include "exp.h"
using namespace std;

//int isNum(string userInput);

const int SIZE = 10;
void setA();
void setB();
void unionSet();
void setC();

int main(){
    cout << endl;
    int input = -1;

    // CREATING SET B
    IntegerSet setA;
    cout << "Enter set A: " << endl;
    do {
        cout << "Enter an element (Type x to stop):";
        cin >> input;
        setA.insetElement(input);
    }
    while(!cin.fail());

    cout << endl;
    
    setA.printSet();
    cout << endl;

    // CREATING SET B
    IntegerSet setB;
    cout << "Enter set B: " << endl;
    do {
        cout << "Enter an element (Type x to stop):";
        cin >> input;
        setB.insetElement(input);
    }
    while(!cin.fail() == true);
    cout << "Entry complete" << endl;
    cout << endl;

    setB.printSet();

    IntegerSet unionSet;
    unionSet.unionOfSets(setA, setB, unionSet);
    unionSet.intersetionOfSets(unionSet);

    setA.isEqualTo(setA, setB);
    cout << "What element would you like to insert into set A?: ";
    cin >> input;
    setA.insetElement(input);

    cout << "Set A is now: " << endl;
    setA.printSet();
    cout << endl;

    cout << "Deleting 77 from set A..." << endl;
    setA.deleteElement(input);
    cout << "Set A is now: " << endl;
    setA.printSet();

    setC();

    return 0;   
}

void setC(){
    // CREATING SET C
    cout << "Now creating a set of specific values and testing the bounds limits." << endl;
    cout << "Creating array of size 10: {25, 67, 2, 9, 99, 105, 45, -5, 100, 1} (Note from instructor:" << endl;
    cout << "SIZEcode this array in your program)" << endl;

    int hardcode[SIZE] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
    IntegerSet setC(hardcode, 10);
    cout << endl;
    cout << "Set C is: " << endl;
    setC.printSet();
    cout << endl;
}

/*
void setElements(IntegerSet & set){
    int num = 0;
    string userInput = "";
    while((num >= 0 && num <= 100)){
        cout << "Enter an element (Type x to stop): ";
        cin >> userInput;

        // ISDIGIT CHECK
        num = isNum(userInput);

        if(num != -1){
            set.inputSet(num);
        }
        cout << endl;
    }
    cout << "Entry complete" << endl;
    cout << endl;
}

int isNum(string userInput){
    int num = -1;
    int strSize = userInput.length();
    for(int i = 0; i <= strSize; i++){
        if(isdigit(userInput[i])){
            num = stoi(userInput);
            return num;
        }
    }
    return num;
}
*/