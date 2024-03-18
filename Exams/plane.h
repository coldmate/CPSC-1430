#ifndef PLANE_H
#define PLANE_H
#include <string>
using namespace std;

class Plane{
    private:
        string airline;
        string make;
        bool takeOff;
        bool land;
        bool flying;
    public:
        string getAirline();
        string getMake();
        bool getTakeOff();
        bool getLand();
        bool getFlying();
        Plane(string airline, string make);
};

#endif