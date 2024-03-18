// Alen Ovalles
// hw4_5.cpp
// Purpose: Implement linked list stack and queue | 1) Calculator(stack) 2) Window (queue)
//
// Input: 1) Very simple expressions with +/- operators, until entered "#"
//        2) Passed in when running a file(string fn) and window size(int k)
//
// Processing: 1) Separates values and operators into different stacks
//             2) Sets queue to the set array, measures windowSize, and set/save int k
//
// Output: 1) Value of expression
//         2) Averages of each window of size k
//
// Example: ./hw4_5.out task2_input.txt 3
//
//          Type the expression (type # to quit): 1+1
//          The value of this expression is 2
//
//          Type the expression (type # to quit): 1--1 
//          The value of this expression is 2
//
//          Type the expression (type # to quit): -1-1 
//          The value of this expression is -2
//
//          Type the expression (type # to quit): 1+-1
//          The value of this expression is 0
//
//          Type the expression (type # to quit): 1-+1 
//          The value of this expression is 0
//          
//          Type the expression (type # to quit): -1-1-1           
//          The value of this expression is -3
//
//          Type the expression (type # to quit): #
//
//          ****Showcasing the second task****
//          The averages in each window of size 3 are [2 3 4 5 6 7 8 9]           
//

#include "Queue.h"
#include "Stack.h"
#include <iostream> 
#include <fstream>
using namespace std;

//********** FIRST TASK FUNCTIONS **********//
void userInput(string & input);
// Asks for user to input an expression

void setStacks(string input, Stack & nums, Stack & ops, int & numCount);
// Parses string using isdigit between two stacks, number stack and operator stack
// '-' = 45 | '+' = 43 (ASCII dec values)

void calculate(Stack & nums, Stack & ops, int numCount);
// Calculates sum of stack of numbers with operators

//********** SECOND TASK FUNCTIONS **********//
void readFile(string fn, Queue & window, int & windowSize);
// Reads the task file, sets Queue window and size of Queue/file

void validInput(int & k, int windowSize);
// Checks if the integer k is valid; less than 1 or greater than window size

void calculateAvg(Queue & window, Queue & averages, int k, int windowSize, int & avgCount);
// Calculates the avgerage of each window given the integer k

void printQueue(Queue & averages, int k, int avgCount);
// Displays the averages of each window with the given integer k

int main(int argc, char * argv[]){

    //********** FIRST TASK VARIABLES **********//
    string input = " ";

    //********** SECOND TASK VARIABLES **********//
    Queue window, averages;
    string fn = argv[1];
    int k = stoi(argv[2]);
    int windowSize = 0;
    int avgCount = 0;

    //********** FIRST TASK **********//
    cout << endl;

    userInput(input);

    while(input != "#"){
        Stack nums, ops;
        int numCount = 0;

        setStacks(input, nums, ops, numCount);

        calculate(nums, ops, numCount);

        cout << "The value of this expression is ";
        cout << nums.pop() << endl << endl;

        userInput(input);
    }

    //********** SECOND TASK **********//
    readFile(fn, window, windowSize);

    validInput(k, windowSize);

    calculateAvg(window, averages, k, windowSize, avgCount);   

    printQueue(averages, k, avgCount);

    return 0;
}

//********** FIRST TASK FUNCTIONS **********//
void userInput(string & input){
    cout << "Type the expression (type # to quit): ";
    cin >> input;
}

void setStacks(string input, Stack & nums, Stack & ops, int & numCount){
    string number = " ";
    int strSize = input.length();
    int k = 0;

    if(input[0] == '-'){
        number += '-';
        k = 1;
    }

    for(int i = k; i < strSize; i++){
        if(isdigit(input[i]) == true){
            number += input[i];
        }
        else{
            if(number == " "){
                int plusMinus = ops.pop();
                if((plusMinus == 43 && input[i] == '-') || (plusMinus == 45 && input[i] == '+')){
                    ops.push('-');
                }
                else{
                    ops.push('+');
                }   
            }
            else{
                ops.push(input[i]);
                nums.push(stoi(number));
                number = " ";
                numCount++;
            }
        }
    }
    nums.push(stoi(number));
    numCount++;
}

void calculate(Stack & nums, Stack & ops, int numCount){
    while(numCount > 1){
        int num1 = nums.pop();
        int num2 = nums.pop();
        int ch = ops.pop();

        if(ch == 45){
            if(!ops.isEmpty()){
                int ch2 = ops.pop();
                if(ch2 == 45){
                    nums.push(-num2 - num1);
                }
                else{
                    nums.push(num2 - num1);
                }
                ops.push('+');
            }
            else{
                nums.push(num2 - num1);
            }
        }
        else{
            nums.push(num1 + num2);
        }
        numCount--;
    }
}

//********** SECOND TASK FUNCTIONS **********//
void readFile(string fn, Queue & window, int & windowSize){
    ifstream file;
    int val;

    file.open(fn);
    cout << endl;

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

void calculateAvg(Queue & window, Queue & averages, int k, int windowSize, int & avgCount){
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
    cout << "]" << endl << endl;
}