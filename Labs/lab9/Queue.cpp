// Alen Ovalles
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size){
    queueArr = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}


Queue::~Queue(){
    delete [] queueArr;
}

void Queue::enqueue(int val){
    if(isFull()){
        cout << "Queue is Full" << endl;
    }
    else{
        rear = (rear + 1) % queueSize;
        queueArr[rear] = val;
        numItems++; 
    }   
}

int Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else{
        front = (front + 1) % queueSize;
        numItems--;
        return queueArr[front];
    }
}

bool Queue::isEmpty() const{
    return numItems == 0;
}

bool Queue::isFull() const{
    return numItems == queueSize;
}
