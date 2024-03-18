// Alen Ovalles
#ifndef FANCYLIST_H
#define FANCYLIST_H 

class FancyList{
    private: 
        struct ListNode{
            int value;
            ListNode * next;
        };

        ListNode * head;

    public:
        FancyList();
        // Default Cosntructor

        ~FancyList();
        // Destructor

        void append(int);
        // Appends user input into list

        void reverse();
        // Reverses linked list

        void deleteNode(int &, int);
        // Deletes node at given n-th node

        void displayList() const;
        // Prints linked list
};
#endif