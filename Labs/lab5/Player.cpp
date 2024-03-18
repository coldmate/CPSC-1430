// Alen Ovalles
#include "Player.h"
#include <iostream>
using namespace std;

Game::Game(int totalGames, string name){
    this->totalGames = totalGames;
    this->name = name;
    this->arr = new int[totalGames];
    counter = 0;
}

void Game::setInput(int input){
    if(counter < totalGames){
        arr[counter] = input;
        counter++;
    }
}

int Game::getInput(int i){
    return arr[i];
}

Game::~Game(){
    delete [] arr;
} 
 