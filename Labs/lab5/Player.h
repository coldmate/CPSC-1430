// Alen Ovalles
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std; 

class Game{
    private:
        int totalGames;
        string name; 
        int * arr;
        int counter;
    public:
        Game(int totalGames, string name);
        // Initializes the name of a player and the member variable that points to an integer array 

        ~Game();
        // Deallocate dynamic memory

        void setInput(int input); 
        // Sets the player selected number to a given index of the array

        int getInput(int i);
        // Returns the selected number at a given index
};
#endif