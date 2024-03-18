// Alen Ovalles
#include "Stack.h"
#include <iostream>
using namespace std;

void userInput(string & input);
void setStacks(string input, Stack & nums, Stack & ops, int & numCount);

int main(){
    string input = " ";

    cout << endl;

    userInput(input);

    while(input != "#"){
        Stack nums, ops;
        int numCount = 0;

        setStacks(input, nums, ops, numCount);

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

        cout << "The value of this expression is ";
        cout << nums.pop() << endl << endl;

        userInput(input);
    }
    cout << endl;

    return 0;
}

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