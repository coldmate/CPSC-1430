// Alen Ovalles
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue{
    private:
        int * queueArr;
        int queueSize;
        int front;
        int rear;
        int numItems;
    public:
        Queue(int);
        ~Queue();

        void enqueue(int val);
        int dequeue();
        bool isEmpty() const;
        bool isFull() const;
};  
  
#endif