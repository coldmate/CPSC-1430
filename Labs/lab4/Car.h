// Alen Ovalles
// Car.h
// Purpose: Declaring member variables and member functions
// Input: None
// Processing: None
// Output: None

#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
    private:
        int yearModel;
        string make;
        int speed;
    public:
        //Getter Functions
        int getYearModel();
        string getMake();
        int getSpeed();

        //Accelerate Function
        void accelerate();

        //Brake Function
        void brake();

        //Welcome Message
        void displayMessage();

        //Constructor 
        Car(int yearModel, string make);
};
#endif