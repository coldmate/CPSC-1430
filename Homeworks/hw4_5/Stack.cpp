// Alen Ovalles
#include "Stack.h"
#include <iostream> 
using namespace std;

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack(){
    StackNode * curr = top;
    StackNode * next = nullptr;

    while(curr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;
}

void Stack::push(int val){
    StackNode * newNode = new StackNode;
    newNode->value = val;
    
    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

int Stack::pop(){
    StackNode * next = nullptr;
    
    if(isEmpty()){
        return -1;
    }
    else{
        int returnValue = top->value;
        next = top->next;
        delete top;
        top = next;
        return returnValue;
    }
}

bool Stack::isEmpty(){
    return top == nullptr;
}