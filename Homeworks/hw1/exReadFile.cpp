#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

void readFile(string fileName, int& counter, int& response, struct covidData states[]);
void displayStates(int counter, struct covidData states[]);

struct covidData {
    string date;
    string name;
    string fips;
    int cases;
    int deaths;
};

int main() {
    int counter;
    int response = 1;
    string fileName;

    covidData *states;
    states = new covidData;

    cout << "Enter file name: ";
    cin >> fileName;
    readFile(fileName, counter, response, states); 
    
    displayStates(counter, states);
}

void readFile(string fileName, int& counter, int& response, struct covidData states[]){
    ifstream file;
    file.open(fileName);

    string date, name, fips, tempCase, tempDeath;
    int cases, deaths, i = 0;

    string myString;
    string line;

    if(file){
        while(getline(file, line)){
            counter++;
        }
        file.clear();
        file.seekg(0);
        


        while(getline(file, line)){
            stringstream ss(line);
            getline(ss, date, ',');
            getline(ss, name, ',');
            getline(ss, fips, ',');
            getline(ss, tempCase, ',');
            getline(ss, tempDeath, ',');
            cases = stoi(tempCase);
            deaths = stoi(tempDeath);

            states[i].date = date;
            states[i].name = name;
            states[i].fips = fips;
            states[i].cases = cases;
            states[i].deaths = deaths;
            i++;
        }
    }
    else {
        cout << "File Not Found" << endl;
        response = 5;
    }
    file.close();
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