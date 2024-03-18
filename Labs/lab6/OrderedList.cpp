// Alen Ovalles
#include "OrderedList.h"
#include <iostream>
using namespace std;

OrderedList::OrderedList(){
    head = nullptr;
}

OrderedList::OrderedList(const OrderedList & temp){
    head = nullptr;
    ListNode * curr = temp.head;

    while(curr){
        insert(curr->value);
        curr = curr->next; 
    }
}
 
OrderedList::~OrderedList(){
    ListNode * nodePtr;
    ListNode * nextNode;
    nodePtr = head;

    cout << "Deallocating..." << endl << endl;
    while(nodePtr){
        nextNode = nodePtr->next;
        cout << "Deleting " << nodePtr->value << endl << endl;
        delete nodePtr;
        nodePtr = nextNode;
    }
    cout << endl;
}

void OrderedList::insert(int num){
    ListNode * newNode = nullptr;
    ListNode * curr = nullptr;
    ListNode * prev = nullptr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
        newNode->next = nullptr;
    }
    else{
        curr = head;
        prev = nullptr;

        while(curr != nullptr && curr->value < num){
            prev = curr;
            curr = curr->next;
        }

        if(prev == nullptr){
            head = newNode;
            newNode->next = curr;
        }
        else{
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void OrderedList::printList() const{
    ListNode * curr = head;

    while(curr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl << endl;
}