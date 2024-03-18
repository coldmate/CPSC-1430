// Alen Ovalles
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

class OrderedList{
    private:
        struct ListNode{
            int value;
            ListNode * next;
        };

        ListNode * head;

    public:
        OrderedList();
        // Default Constructor

        OrderedList(const OrderedList & temp);
        // Copy Constructor

        ~OrderedList();
        // Destructor

        void insert(int value);
        // Insert value into linked list

        void printList() const;
        // Print linked list

};
#endif