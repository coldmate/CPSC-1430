// Alen Ovalles
#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <string>
using namespace std;

class IntegerSet{
    private: 
        const int SIZE = 101;
        int set[101]; 
        int size;

        bool isNum(string userInput);
        // isNum fxn is to check the user's input if they have inputed a 'x' for to exit out of the set
        // Would have been easier if we checked if user inputed an -1,
        // but professor wanted (Type x to stop), couldn't figure out another way

    public:
        IntegerSet();
        // Constructor initializes a set to the so-called “empty-set”, i.e., 
        // a set whose array representation contains all zeros

        IntegerSet(int arr[], int size);
        // Constructor receives an array of integers and the size of that array 
        // and uses the array to initialize a set object

        IntegerSet unionOfSets(IntegerSet setB);
        // Creates a third set that is the set-theoretic union of two existing sets 
        // (i.e., an element of the third array’s is set to 1 if that element is 1 in either 
        // or both of the existing sets, and an element of the third set’s array 
        // is set to 0 if that element is 0 in each of the existing sets)

        IntegerSet intersetionOfSets(IntegerSet setB);
        // Creates a third set which is the set-theoretic intersection of two existing sets 
        // (i.e., an element of the third set’s array is set to 0 if that element is 0 in either 
        // or both of the existing sets, and an element of the third set’s array 
        // is set to 1 in each of the existing sets)

        void insertElement(int k);
        // Inserts a new integer k into a set (be setting set[k] to 1)

        void deleteElement(int m);
        // Deletes integer m (by setting set[m] to 0)

        void printSet();
        // Prints a set as a list of numbers separated by spaces
        // Print only those elements that are present in the set 
        // (i.e., their position in the array has a value of 1)
        // Print – for an empty set

        bool isEqualTo(IntegerSet setB);
        // Checks and finds out if both sets are equal

        void emptySet();
        // Sets all elements of a set to 0

        void inputSet();
        // Reads value from user into the set

        bool validEntry(int k);
        // Determines a valid entry to the set (i.e., in the range 0 through 100)
};

#endif