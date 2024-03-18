// From memory
// For the final exam 


// DYMANIC STACK
class Stack{
    private:
        struct Node{
            int value;
            Node * next;
        }
        Node * top;

    public:
        Stack();
        ~Stack();

        void push(int);
        int pop();
        void isEmpty() const;
}

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack(){
    Node * curr = top;
    Node * next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;
}

void Stack::push(int val){
    //Node * curr = nullptr; Don't need
    Node * newNode = new Node;
    newNode->value = val;
    

    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;

    }
    else{
        //curr = top;
        //curr->next = newNode;
        newNode->next = top;
        top = newNode;
    }
}

int Stack::pop(){
    Node * next = nullptr;

    if(isEmpty()){
        return -1;
    }
    else{
        int returnVal = top->value;
        next = top->next;
        delete top;
        top = next;
        return returnVal;
    }
}

void Stack::isEmpty() const{
    return top == nullptr;
}

// DYNAMIC QUEUE
class Queue{
    private:
        struct Node{
            int value;
            Node * next;
        }
        Node * front;
        Node * rear;
        int elements;
    public:
        Queue();
        ~Queue();

        void enqueue(int);
        int dequeue();
        void isEmpty() const;
}

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
    elements = 0;
}

Queue::~Queue(){

    while(!elements){
        dequeue();
    }
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int val){
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
        
    }
    else{
        rear->next = newNode // FORGOT THIS LINE
        rear = newNode;
        
    }
    elements++;
}

int Queue::dequeue(){
    Node * next = nullptr;

    if(isEmpty()){
        return -1;
    }
    else{
        int returnVal = front->value;
        next = front->next;
        delete front;
        front = next;
        return returnVal;
    }
}

void Queue::isEmpty() const{
    return elements == 0;
}

// STATIC STACK 
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
        void isEmpty() const;
        void isFull() const;
}

Stack::Stack(int size){
    stackArr = new int[size];
    stackSize = size;
    top = -1;
}

Stack::~Stack(){
    delete [] stackArr;
}

void Stack::push(int val){
    if(isFull()){
        cout << "Stack is full" << endl;
    }
    else{
        top++;
        stackArr[top] = val;
    }
}

int Stack::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }
    else{
        int returnVal = stackArr[top];
        top--;
        return returnVal;
    }
}

void Stack::isEmpty() const{
    return top == -1;
}

void Stack::isFull() const{
    return top == stackSize - 1;
}

// STATIC QUEUE
class Queue{
    private:
        int * queueArr;
        int queueSize;
        int front;
        int rear;
        int elements;

    public:
        Queue(int);
        ~Queue();

        void enqueue(int);
        int dequeue();
        void isEmpty() const;
        void isFull() const;
}

Queue::Queue(int size){
    queueArr = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    elements = 0;
}

Queue::~Queue(){
    delete [] queueArr;
}

void Queue::enqueue(int val){
    if(isFull()){
        cout << "Queue is full" << endl;
    }
    else{
        rear = (rear + 1) % queueSize;
        elements++;
        queueArr[rear] = val;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        front = (front + 1) % queueSize;
        elements--;
        return queueArr[front];
    }
}

void Queue::isEmpty() const{
    return elements == 0
}

void Queue::isFull() const{
    return elements == queueSize; // NOT queueSize - 1
}

// 