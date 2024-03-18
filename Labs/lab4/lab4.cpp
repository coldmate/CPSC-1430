// Alen Ovalles
// lab4.cpp
// Purpose: Implementing a class across multiple files; main function
// Input: None
// Processing: Created a constructor, member funtions and getter functions
// Output: Demonstrate the class in a driver program that creates a Car object, 
//         displays current speed after increase/decrease by 5 mph

#include <iostream>
#include "Car.h"
using namespace std;

const int COUNT = 5;

void increase(Car & model);
// Adds 5 to the current speed 
// Prints out the current speed

void decrease(Car & model);
// Subtracts 5 to the current speed 
// Prints out the current speed

int main (){
    Car model(1999, "Honda");

    // Displays car details, ie, year model, car brand, and 
    // current speed (which is set to 0)
    model.displayMessage();

    // Calls the accelerate function 5 times
    increase(model);

    // Calls the brake function 5 times 
    decrease(model);

    return 0;
}

void increase(Car & model){
    cout << "Increasing current speed by 5 mph" << endl;
    for(int i = 0; i < COUNT; i++){
        model.accelerate();
    }
    cout << endl;
}

void decrease(Car & model){
    cout << "Decreasing current speed by 5 mph" << endl;
    for(int i = 0; i < COUNT; i++){
        model.brake();
    }
    cout << endl;
}