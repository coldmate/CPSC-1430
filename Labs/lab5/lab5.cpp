// Alen Ovalles
// lab5.cpp
// Purpose: Classes and Objects
// Input: Player 1 and 2 names, amount of games, and player elements
// Processing: Stores player's elements in arr and compare arrays
// Output: Print winner
// Example: Enter total games: 3
//          
//          Player 1 Name: Jim
//          Enter element: 1
//          Enter element: 10
//          Enter element: 5
//
//          Player 2 Name: Bob
//          Enter element: 2
//          Enter element: 8
//          Enter element: 50
//
//          Bob Won

#include "Player.h"
#include <iostream>
using namespace std;

void player1Turn(Game & Player1, string player1, int totalGames);
// Asks for Player 1 input
// Prints out the array of Player 1

void player2Turn(Game & Player2, string player2, int totalGames);
// Asks for Player 2 input
// Prints out the array of Player 2

void winner(Game & Player1, Game & Player2, string player1, string player2, int toatlGames);
// Calculates and prints which Player is the winner

int main(int argc, char *argv[]){
    int totalGames;
    string player1, player2;

    // AMOUNT OF GAMES
    cout << endl;
    cout << "Please enter the total number of games: ";
    cin >> totalGames;
    cout << endl << endl;

    // PLAYER 1 TURN
    cout << "Please enter the name of first player: ";
    cin >> player1;
    cout << endl;
    Game Player1(totalGames, player1);
    player1Turn(Player1, player1, totalGames);

    // PLAYER 2 TURN
    cout << "Please enter the name of second player: ";
    cin >> player2;
    cout << endl;
    Game Player2(totalGames, player2);
    player2Turn(Player2, player2, totalGames);

    // WINNER
    winner(Player1, Player2, player1, player2, totalGames);

    return 0; 
}

void player1Turn(Game & Player1, string player1, int totalGames){
    int input;

    for(int i = 0; i < totalGames; i++){
        cout << "Please enter a number at index " << i+1 << " for player " << player1 << ": ";
        cin >> input;
        Player1.setInput(input);
        cout << endl;
    }
    cout << "Player " << player1 << " selected the following numbers: ";
    for(int i = 0; i < totalGames; i++){
        cout << Player1.getInput(i) << " ";
    }
    cout << endl << endl;
}

void player2Turn(Game & Player2, string player2, int totalGames){
    int input;

    for(int i = 0; i < totalGames; i++){
        cout << "Please enter a number at index "<< i+1 << " for player " << player2 << ": ";
        cin >> input;
        Player2.setInput(input);
        cout << endl;
    }
    cout << "Player " << player2 << " selected the following numbers: ";
    for(int i = 0; i < totalGames; i++){
        cout << Player2.getInput(i) << " ";
    }
    cout << endl << endl;    
}

void winner(Game & Player1, Game & Player2, string player1, string player2, int totalGames){
    int p1Points, p2Points;
    for(int i = 0; i < totalGames; i++){
        if(Player1.getInput(i) > Player2.getInput(i)){
            p1Points++;
        }
        else{
            p2Points++;
        }
    }
    if(p1Points > p2Points){
        cout << player1 << " Won" << endl;
    }
    else{
        cout << player2  << " Won" << endl;
    }
    cout << endl;
}