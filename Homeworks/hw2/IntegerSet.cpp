// Alen Ovalles
#include <iostream>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet(){
    emptySet();
}

IntegerSet::IntegerSet(int arr[], int size) {
    this->size = size;
    emptySet();
    for(int i = 0; i < this->size; i++){
        int k = arr[i];
        if(validEntry(k)){
            set[k] = 1;
        }
    }
}

IntegerSet IntegerSet::unionOfSets(IntegerSet setB){
    IntegerSet result;
    for(int i = 0; i < SIZE; i++){
        if(set[i] == 1 || setB.set[i] == 1){
            result.set[i] = 1;
        }
    }
    return result;
}

IntegerSet IntegerSet::intersetionOfSets(IntegerSet setB){
    IntegerSet middle;
    for(int i = 0; i < SIZE; i++){
        if(set[i] == 1 && setB.set[i] == 1){
            middle.set[i] = 1;
        }
    }
    return middle;
}   

void IntegerSet::insertElement(int k){
    if(validEntry(k)){
        set[k] = 1;
    }
}

void IntegerSet::deleteElement(int m) {  
    set[m] = 0;
}

void IntegerSet::printSet(){
    int count = 0;

    for(int i = 0; i < SIZE; i++){
        if(set[i] == 1){
            count++;
        }
    }

    if(count >= 1){
        cout << "{ ";
        for(int i = 0; i < SIZE; i++){
            if(set[i] != 0){
                cout << i << " ";
            }
        }
        cout << "}" << endl;
    }
    else{
        cout << "{ - }" << endl;
    }
    cout << endl;
}

bool IntegerSet::isEqualTo(IntegerSet setB){
    for(int i = 0; i < SIZE; i++){
        if(set[i] != setB.set[i]){
            return false; 
        }
    }
    return true;
}

void IntegerSet::emptySet(){
    for(int i = 0; i < SIZE; i++){
        set[i] = 0;
    }
}
 
bool IntegerSet::isNum(string userInput){
    int strSize = userInput.length();
    for(int i = 0; i < strSize; i++){
        if(isdigit(userInput[i])){
            return true;
        }
    }
    return false;
}

void IntegerSet::inputSet(){
    int k;
    string userInput = "";
    cout << "Enter an element (Type x to stop): ";
    cin >> userInput; 
    while(isNum(userInput)){
        k = stoi(userInput);
        insertElement(k);

        cout << endl;
        cout << "Enter an element (Type x to stop): ";
        cin >> userInput; 
    }
    cout << endl;
    cout << "Entry complete" << endl;
    cout << endl;
    
}

bool IntegerSet::validEntry(int k){
    if(k > 100 || k < 0){
        cout << "Invalid insert of " << k << " attempted!" << endl;
        return false;
    }
    return true;
}