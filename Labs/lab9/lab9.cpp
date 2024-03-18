// Alen Ovalles
// lab9.cpp
// Purpose: Implement your own stack and queue
// Input: An integer k, to reverse the order of queue
// Processing: Given the int k, reverse order of queue/stack 
// Ouput: Display orginal array, then reverse array at the given int k
//
// Example: ./lab9.out 2 || ./a.out 2
//          
//          Original   array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//          Reversed first 2: [2, 1, 3, 4, 5, 6, 7, 8, 9, 10]
//

#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

const int SIZE = 10;

void isValid(int & k);
// Checks if the second argument int k is in range of queue size

void setQueue(Queue & queue);
// Hardcodes queue from {1,2,3,4,5,6,7,8,9,10}

void setReverse(int reverseArr[], Queue & queue, Stack & stack, int k);
// Reverse the order of the first k integers from queue and stack

void printArr(int reverseArr[], int k);
// Displays reversed array at the given int k

int main(int argc, char * argv[]){
    Stack stack(SIZE);
    Queue queue(SIZE);

    int k = stoi(argv[1]); // argv[1] due to the nature of ./lab9.out # or .a/.out # verse ./a.out lab9.cpp # 
    int reverseArr[SIZE];

    isValid(k);

    setQueue(queue);  

    setReverse(reverseArr, queue, stack, k);

    printArr(reverseArr, k);
}

void isValid(int & k){
    while(k <= 0 || k > SIZE){
        cout << "Invalid integer, enter a new integer between 1-10: ";
        cin >> k;
    }
}

void setQueue(Queue & queue){
    cout << endl;
    cout << "Original   array: [";
    for(int i = 0; i < SIZE; i++){
        if(i+1 < SIZE){
            cout << i+1 << ", ";
        }
        else{
            cout << SIZE;
        }
        queue.enqueue(i+1);
    }
    cout << "]" << endl;    
}

void setReverse(int reverseArr[], Queue & queue, Stack & stack, int k){
    for(int i = 0; i < k; i++){
        stack.push(queue.dequeue());
    }

    for(int i = 0; i < SIZE; i++){
        if(i < k){
            reverseArr[i] = stack.pop();
        }
        else{
            reverseArr[i] = queue.dequeue();
        }
    }
}

void printArr(int reverseArr[], int k){
    cout << "Reversed first " << k << ": [";
    for(int n = 0; n < SIZE; n++){
        if(n+1 < SIZE){
            cout << reverseArr[n] << ", " ;
        }
        else{
            cout << reverseArr[n];
        }
    }
    cout << "]" << endl << endl;
}
