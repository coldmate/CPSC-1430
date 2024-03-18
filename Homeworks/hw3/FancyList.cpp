// Alen Ovalles
#include "FancyList.h"
#include <iostream>
using namespace std;

FancyList::FancyList(){
    head = nullptr;
} 

FancyList::~FancyList(){
    ListNode * curr;
    ListNode * next;
    curr = head;

    cout << "Deallocating..." << endl;
    while(curr){
        cout << "Deleting " << curr->value << endl;
        next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    cout << endl;
}

void FancyList::append(int num){
    ListNode * newNode;
    ListNode * curr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    }
    else{
        curr = head;

        while(curr->next){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void FancyList::reverse(){
    ListNode * curr = nullptr;
    ListNode * prev = nullptr;
    ListNode * next = nullptr; 
    curr = head;
    
    if(!head){
        return;
    }

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void FancyList::deleteNode(int & counter, int num){
    ListNode * curr = nullptr;
    ListNode * prev = nullptr;
    int node = counter - num;
    
    if(!head){
        return;
    }
    
    if(node == 0){
        curr = head->next;
        delete head;
        head = curr;
    }
    else{
        curr = head;
         
        for(int i = 0; i < node; i++){
            prev = curr;
            curr = curr->next;
        }
        
        if(curr){
            prev->next = curr->next;
            delete curr;
        }
    }
    counter--;
}

void FancyList::displayList() const{
    ListNode * curr = head;

    while(curr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl << endl;
}