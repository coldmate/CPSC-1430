// Alen Ovalles
#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size){
    stackArr = new int[size];
    stackSize = size;
    top = -1;
}

Stack::~Stack(){
    delete [] stackArr;
}

void Stack::push(int val){
    if(isFull()){
        cout << "Stack is full." << endl;
    }
    else{
        top++;
        stackArr[top] = val;
    }
}

int Stack::pop(){
    if(isEmpty()){
        cout << "The stack is empty." << endl;
        return -1;
    }
    else{
        int returnVal = stackArr[top];
        top--;
        return returnVal;
    }
}

bool Stack::isEmpty() const{
    return top == -1;
}

bool Stack::isFull() const{
    return top == stackSize - 1;
}
