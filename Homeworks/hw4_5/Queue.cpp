// Alen Ovalles 
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

Queue::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
    front = nullptr;
}

void Queue::enqueue(int val){
    QueueNode * newNode = new QueueNode;
    newNode->value = val;
    newNode->next = nullptr;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

int Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else{
        int val = front->value;
        QueueNode * temp = front;

        front = front->next;

        delete temp;
        numItems--;
        return val;
    }
}

bool Queue::isEmpty() const{
    return numItems == 0;
}
