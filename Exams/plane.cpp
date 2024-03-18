#include <iostream>
#include "plane.h"
using namespace std;

Plane::Plane(string airline, string make){
    this -> airline = airline;
    this -> make = make;
    takeOff = false;
    land = false;
    flying = false;
}

string Plane::getAirline(){
    return airline;
}

string Plane::getMake(){
    return make;
}

bool Plane::getTakeOff(){
    return takeOff;
}

bool Plane::getLand(){
    return land;
}

bool Plane::getFlying(){
    return flying;
}