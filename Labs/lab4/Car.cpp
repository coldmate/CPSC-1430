// Alen Ovalles
// Car.cpp
// Purpose: Defining member functions
// Input: None
// Processing: Return member variables and prints
// Output: None

#include <iostream>
#include "Car.h"
using namespace std;

const int MPH = 5;

//Getter Functions
int Car::getYearModel(){
    return yearModel;
}

string Car::getMake(){
    return make;
}

int Car::getSpeed(){
    return speed;
}

//Accelerate Function
void Car::accelerate(){
    speed += MPH;
    cout << "Currect speed: " << speed << " mph" << endl;
}

//Brake Function
void Car::brake(){
    speed -= MPH;
    cout << "Current speed: " << speed << " mph" << endl;
}

//Welcome Message 
void Car::displayMessage(){
    cout << endl;
    cout << "******CAR MODEL******" << endl;
    cout << "Year Model: " << getYearModel() << endl;
    cout << "Car Brand: " << getMake() << endl;
    cout << "Current Speed: " << getSpeed() << " mph" << endl << endl;
}

//Constructor
Car::Car(int yearModel, string make){

    cout << endl;
    cout << "Setting year model..." << endl;
    cout << "Setting car brand..." << endl;
    cout << "Setting current speed..." << endl;

    this->yearModel = yearModel;
    this->make = make;
    speed = 0;
}

