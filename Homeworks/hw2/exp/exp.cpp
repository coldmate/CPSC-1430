// Alen Ovalles
// IntegerSet.cpp
// Purpose: Writing a Class; Defining member functions
// Input: None
// Processing: None
// Output: None

#include <iostream>
#include "exp.h"
using namespace std;


// Defines a set to the so-called “empty-set”
// contains an array all of zeros
IntegerSet::IntegerSet(){
    this->size = 101;
    this->setptr = new bool[size];
    emptySet();
}

IntegerSet::IntegerSet(int arr[], int arrSize) {
    this->size = 101;
    this->setptr = new bool[size];

    for(int i = 0; i < arrSize; i++){
        validEntry(arr[i]);
        if(arr[i] != -1){
            this->setptr[arr[i]] = true;
        }
    }
}

void IntegerSet::unionOfSets(IntegerSet setA, IntegerSet setB, IntegerSet & unionSet){
    for(int i = 0; i < size; i++){
        if(setA.setptr[i] == 1 || setB.setptr[i] == 1){
            unionSet.setptr[i] = 1;
        }
    }
    cout << "Union of A and B is: " << endl;
    unionSet.printSet();
}

void IntegerSet::intersetionOfSets(IntegerSet unionSet){
    int mid = 0;
    for(int i = 0; i < size; i++){
        if(unionSet.setptr[i] == true){
            mid++;
        }
    }
    cout << "Intersection of A and B is: " << endl;
    if(mid == 0){
        cout << "{ - }" << endl;
    }
    else if(mid % 2 == 0){
        mid /= 2;
        cout << "{ " << unionSet.setptr[mid] << " " << unionSet.setptr[mid+1] << " }" << endl;
    }
    else{
        mid /= 2;
        cout << "{ " << unionSet.setptr[mid] << " }" << endl;
    }
    cout << endl;
}   

void IntegerSet::insetElement(int k){
    if(setptr[k] == false){
        setptr[k] = true;
    }
}

void IntegerSet::deleteElement(int m){  
    setptr[m] = 0;
}

void IntegerSet::printSet(){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(setptr[i] == true){
            count++; 
        }
    }
    
    if(count > 0){
        cout << "{ ";
        for(int i = 0; i < size; i++){
            if(setptr[i] == true){
                cout << i << " ";
                count++; 
            }
        }
        cout << "}";
    }
    else{
        cout << "{ - }" << endl;
    }
    cout << endl;
}

void IntegerSet::isEqualTo(IntegerSet setA, IntegerSet setB){
    int count;
    for(int i = 0; i < size; i++){
        if(setA.setptr[i] != setB.setptr[i]){
            count++;
        }
    }
    if(count > 0){
        cout << "Set A is not equal to Set B is" << endl;
    }
    else{
        cout << "Set A is equal to Set B" << endl;
    }
}

void IntegerSet::emptySet(){
    for(int i = 0; i < size; i++){
        setptr[i] = false;
    }
}

void IntegerSet::inputSet(int k){
    
}

void IntegerSet::validEntry(int & k){
    if(k > 100 || k < 0){
        cout << "Invalid insert of "<< k << " attempted! " << endl;
        k = -1;
    }
}

/*
IntegerSet::~IntegerSet(){
    delete [] setptr;
}
*/


