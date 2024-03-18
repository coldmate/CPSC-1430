#ifndef EXP_H
#define EXP_H
#include <string>
using namespace std;

class IntegerSet{
    private:
        bool * setptr; 
        int size;

    public:
        IntegerSet();
        IntegerSet(int arr[], int arrSize);
        //~IntegerSet();
        void unionOfSets(IntegerSet setA, IntegerSet setB, IntegerSet & unionSet);
        void intersetionOfSets(IntegerSet unionSet);
        void insetElement(int k);
        void deleteElement(int m);
        void printSet();
        void isEqualTo(IntegerSet setA, IntegerSet setB);
        void emptySet();
        void inputSet(int k);
        void validEntry(int & k);
};

#endif