// Alen Ovalles
// array.cpp
// Purpose: Dynamic Memory Allocation
// Input: row, col, elements of array
// Processing: calcuates sum of each row and each col
// Output: prints array, sums of row and col
// Examples: row = 2; col = 2; input: 1 2 3 4 
//           1 2 
//           3 4
//
//           Sum of row 1 is 3 
//           Sum of row 1 is 7
//           Sum of col 1 is 4
//           Sum of col 1 is 6

#include <iostream>

using namespace std;

void printArr(int ** arr, int row, int col);
void sums(int ** arr, int row, int col);

int main(int argc, char *argv[]) {

    int ** arr;
    int row;
    int col;

    cout << endl;
    cout << "Input row" << endl;
    cin >> row;
    cout << endl;

    cout << "Input col" << endl;
    cin >> col;
    cout << endl;

    arr = new int * [row];

    for(int i = 0; i < row; i++){
        arr[i] = new int [col];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Input number at row " << i+1 << " col " << j+1 << endl;
            cin >> arr[i][j];
            cout << endl;
        }
    }

    printArr(arr, row, col);

    sums(arr, row, col);

    delete [] arr;
    arr = nullptr;
}

void printArr(int ** arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sums(int ** arr, int row, int col){
    for(int i = 0; i < row; i++){
        int rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i+1 << " is " << rowSum << endl;
    }

    for(int i = 0; i < col; i++){
        int colSum = 0;
        for(int j = 0; j < row; j++){
            colSum += arr[j][i];
        }
        cout << "Sum of col " << i+1 << " is " << colSum << endl;
    }
    cout << endl;
}