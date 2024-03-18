// Alen Ovalles
#ifndef QUEUE_H
#define QUEUE_H

class Queue{ 
    private:
        struct QueueNode{
            int value;
            QueueNode * next = nullptr;
        };

        QueueNode * front;
        QueueNode * rear;
        int numItems; 
    public:
        Queue();
        ~Queue();

        void enqueue(int val);
        int dequeue();
        bool isEmpty() const;
};  

#endif 