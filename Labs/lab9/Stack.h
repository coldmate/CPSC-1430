// Alen Ovalles
#ifndef STACK_H
#define STACK_H

class Stack{
    private:
        int * stackArr;
        int stackSize;
        int top;

    public:
        Stack(int); 
        ~Stack();
        
        void push(int);
        int pop();
        bool isEmpty() const;
        bool isFull() const;
};

#endif 