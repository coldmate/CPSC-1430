// Alen Ovalles
#include "Queue.h"
#include <iostream>
#include <fstream>
using namespace std;

void readFile(string fn, Queue & window, int & windowSize);
void validInput(int & k, int windowSize);
void printAverage(Queue & window, Queue & averages, int k, int windowSize, int & avgCount);
void printQueue(Queue & averages, int k, int avgCount);

int main(int argc, char * argv[]){
    Queue window, averages;
    string fn = argv[1];
    int k = stoi(argv[2]);
    int windowSize = 0;
    int avgCount = 0;

    readFile(fn, window, windowSize);

    validInput(k, windowSize);

    printAverage(window, averages, k, windowSize, avgCount);   

    printQueue(averages, k, avgCount);

    return 0;
}

void readFile(string fn, Queue & window, int & windowSize){
    ifstream file;
    int val;

    file.open(fn);

    if(file){
        while(file >> val){ 
            window.enqueue(val);
            windowSize++;
        }
    }
    else{
        cout << "Error... File Not Found" << endl;
    }
    file.close();
}

void validInput(int & k, int windowSize){
    while(k < 1 || k > windowSize){
        cout << "Invalid k value, enter new value between (1-" << windowSize << "): ";
        cin >> k;
    }
}

void printAverage(Queue & window, Queue & averages, int k, int windowSize, int & avgCount){
    int avgNum = 0;

    if(k == 1){
        for(int i = 0; i < windowSize; i++){
            avgNum = window.dequeue();
            averages.enqueue(avgNum);
            avgCount++;
        }
    }
    else if(k == windowSize){
        for(int i = 0; i < windowSize; i++){
            avgNum += window.dequeue();
        }
        avgCount = 1;
        avgNum = avgNum / k;
        averages.enqueue(avgNum);
    }
    else{
        avgCount = (windowSize - k) + 1;
        for(int i = 0; i < avgCount; i++){    
            Queue temp;      
            
            for(int i = 1; i <= windowSize; i++){
                if(!window.isEmpty()){
                    int num = window.dequeue();
                    temp.enqueue(num);

                    if(i <= k){
                        avgNum += num;
                    }
                }
                else{
                    i = windowSize+1;
                }
            }

            avgNum = avgNum / k;
            averages.enqueue(avgNum);
            avgNum = 0;

            temp.dequeue();
            
            while(!temp.isEmpty()){
                window.enqueue(temp.dequeue());
            }
        }
    }
}

void printQueue(Queue & averages, int k, int avgCount){
    cout << "****Showcasing the second task****" << endl;

    if(avgCount == 1){
        cout << "The averages in each window of size " << k << " is ["; 
    }
    else{
        cout << "The averages in each window of size " << k << " are ["; 
    }

    for(int i = 0; i < avgCount; i++){
        if(i < avgCount - 1){
            cout << averages.dequeue() << " ";
        }
        else{
            cout << averages.dequeue(); 
        }
    }
    cout << "]" << endl;
}