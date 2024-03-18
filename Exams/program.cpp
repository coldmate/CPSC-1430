#include <iostream>
#include "plane.h"
using namespace std;

int main (){
    Plane example("Alaska", "Boeing");

    cout << endl;
    cout << "******Airplane Ticket******" << endl;
    cout << "Airline: " << example.getAirline() << endl;
    cout << "Make: " << example.getMake() << endl;
    cout << "Take off status: " << example.getTakeOff() << endl;
    cout << "Land status: " << example.getLand() << endl;
    cout << "Flying status: " << example.getFlying() << endl;
    cout << endl;
    return 0;
}