// Alen Ovalles
#ifndef STACK_H
#define STACK_H

class Stack{
    private:
        struct StackNode{
            int value;
            StackNode * next;
        };
        StackNode * top;
    public:
        Stack();
        ~Stack();
        void push(int);
        int pop();
        bool isEmpty();
};

#endif