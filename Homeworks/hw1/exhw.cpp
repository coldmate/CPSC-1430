// Alen Ovalles
// exhw.cpp
// Purpose: Dynamic Memory Allocation
// Input: Filename -> "covid_input1.txt"
// Processing: none
// Output: none
// Examples: none

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void menu(int& response);
// Prints the menu and takes input
// Pass by reference of the response

bool readFile(string fileName, int& counter);
// Reads, counts and retuns that amount of lines in the file
// Pass by reference of the counter

void storeFile(string fileName, int counter, struct covidData states[]);
// Reads and stores file into the struct 

void displayStates(int counter, struct covidData states[]);
// Prints state's name, cases and deaths

void mostCases(int counter, struct covidData states[]);
// Calculates which state has the most cases
// Prints state's name that has the mose cases

void mostDeaths(int counter, struct covidData states[]);
// Calculates which state has the most deaths
// Prints state's name that has the mose deaths

void averages(int counter, struct covidData states[]);
// Calculates the sum of cases/deaths
// Calculates the average death rate with the sum of cases/deaths
// Calculates out of the states over 100 deaths, the state death rate
// Prints option 4's output; total cases/deaths, death rate, state rate

struct covidData {
    string date;
    string name;
    string fips;
    int cases;
    int deaths;
};

int main() {
    bool input;
    int counter;
    int response;
    string fileName;

    cout << "Please enter the input file name: ";
    cin >> fileName;
    cout << endl;

    input = readFile(fileName, counter);

    covidData *states;
    states = new covidData[counter];

    storeFile(fileName, counter, states);
    
    while(input){
        menu(response);

        if(response == 1){
            displayStates(counter, states);
        }
        else if(response == 2){
            mostCases(counter, states);
        }
        else if(response == 3){
            mostDeaths(counter, states);
        }
        else if(response == 4){
            averages(counter, states);
        }
        else {
            input = false;
        }
    }

    // deletes the array pointer 
    delete [] states;
}

bool readFile(string fileName, int& counter){
    ifstream file;
    file.open(fileName);

    string line;

    if(file){
        while(getline(file, line)){
            counter++;
        }
    }
    else {
        cout << "File Not Found" << endl << endl;
        return false;
    }
    file.close();
    return true;
}

void storeFile(string fileName, int counter, struct covidData states[]){
    ifstream file;
    file.open(fileName);

    string date, name, fips, tempCase, tempDeath;
    int cases, deaths, i = 0;

    
    while(getline(file, states[i].date, ',')) {
        getline(file, states[i].name, ',');
        getline(file, states[i].fips, ',');
        getline(file, tempCase, ',');
        getline(file, tempDeath);

        cases = stoi(tempCase);
        deaths = stoi(tempDeath);

        states[i].cases = cases;
        states[i].deaths = deaths;

        i++;
    }
    file.close();
}

void menu(int& response){
    response = 0;
    while(response < 1  or response > 5){
        cout << "************Menu************" << endl;
        cout << "1. Display the COVID info of all states" << endl;
        cout << "2. Display the COVID info of the state that has the most cases" << endl;
        cout << "3. Display the COVID info of the state that has the most deaths" << endl;
        cout << "4. Display the statistics of all states" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> response;
        cout << endl;
    }
}

void displayStates(int counter, struct covidData states[]){
    cout << setw(25) << right << "**States**";
    cout << setw(15) << right << "**Cases**";
    cout << setw(15) << right << "**Deaths**" << endl;

    for(int i = 0; i < counter; i++){
        cout << setw(25) << right << states[i].name;
        cout << setw(15) << right << states[i].cases;
        cout << setw(15) << right << states[i].deaths << endl;
    }
    cout << endl;
}

void mostCases(int counter, struct covidData states[]){
    int mostCase = states[0].cases;
    int caseIndex = 0;
    for(int i = 1; i < counter; i++){
        if(states[i].cases > mostCase){
            mostCase = states[i].cases;
            caseIndex = i;
        }
    }
    cout << states[caseIndex].name << " has the most cases: " << states[caseIndex].cases << endl << endl;
}

void mostDeaths(int counter, struct covidData states[]){
    int mostDeath = states[0].deaths;
    int deathIndex = 0;
    for(int i = 1; i < counter; i++){
        if(states[i].deaths > mostDeath){
            mostDeath = states[i].deaths;
            deathIndex = i;
        }
    }
    cout << states[deathIndex].name << " has the most deaths: " << states[deathIndex].deaths << endl << endl;
}

void averages(int counter, struct covidData states[]){
    float stateRate = (float(states[0].deaths) / float(states[0].cases)) * 100;

    int totalDeaths = 0, totalCases = 0, avgCases = 0, avgDeaths = 0, index = 0;
    float deathRate = 0;

    for(int i = 0; i < counter; i++){
        totalCases += states[i].cases;
        totalDeaths += states[i].deaths;
    }
    avgCases = totalCases / counter;
    avgDeaths = totalDeaths / counter;
    deathRate = (float(avgDeaths) / float(avgCases)) * 100;

    for(int j = 1; j < counter; j++){
        if(states[j].deaths > 100){
            float topRate = (float(states[j].deaths) / float(states[j].cases)) * 100;
            if(topRate > stateRate){
                index = j;
                stateRate = topRate;
            }
        }
    }

    cout << "(a) There are " << totalCases << " cases in total, " << avgCases << " on average" << endl;
    cout << "(b) There are " << totalDeaths << " deaths in total, " << avgDeaths << " on average" << endl;
    cout << "(c) The average death rate for all states is " << setprecision(2) << fixed << deathRate << "%" << endl;
    cout << "(d) Among all states that have more than 100 deaths, ";
    cout << states[index].name << " has the highest death rate of " << setprecision(2) << fixed << stateRate << "%" << endl << endl;
}
