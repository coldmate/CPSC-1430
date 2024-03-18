class Object{
    private:
        struct Node{
            int value;
            Node * next;
        }
        Node * head;
    public:
        Object();
        ~Object();

        void traverse() const;
        void append(int);
        void insert(int);
        void deleteNum(int);

        //void reverse();
        void deleteEndNode(int);
        //void mergedList();
        void findMiddle();
        void deleteTarget(int);
        void deleteDup();
}

Object::Object{
    head = nullptr;
}

Oject::~Object(){
    Node * curr = nullptr;
    Node * next = nullptr;
    curr = head;

    while(curr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

void Object::traverse() const{
    Node * curr = head;

    if(!head){
        cout << "List is empty" << endl;
    }

    while(curr){
        cout << curr.value << endl;
        curr = curr->next;
    }
}

void Object::append(int val){
    Node * curr = nullptr;
    Node * prev = nullptr;

    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    }
    else{
        curr = head;
        while(curr){
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }
}

void Object::insert(int val){
    Node * curr = nullptr;
    Node * prev = nullptr;

    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    }

    curr = head;

    if(head->value > val){
        head = newNode;
        newNode->next = curr;
    }
    else{
        while(curr != nullptr && curr->value > val){
            prev = curr;
            curr = curr->next;
        }
        if(prev){
            head = newNode;
            newNode->next = curr;
        }
        else{
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void Object::deleteNum(int val){
    Node * curr = nullptr;
    Node * prev = nullptr;

    if(!head){
        cout << "List is empty" << endl;
    }
    else{
        while(curr != nullptr && curr->value != val){
            prev = curr;
            curr = curr->next;
        }
        if(curr){
            prev->next = curr->next;
            delete curr;
        }
        else{
            cout << "Value isn't in list" << endl;
        }
    }
}

// COPY CONSTRUCTOR
Object::Object(const Object & temp){
    maxSize = temp.maxSize;
    size = temp.size;
    ptr = new int[size];
    for(int i = 0; i < size; i++){
        ptr[i] = temp.ptr[i];
    }
}

// OPERATOR FUNCTION
const Object & Object::operator=(const Object & right){
    if(ptr != right.ptr){
        delete [] ptr;
        maxSize = right.Maxsize;
        size = right.size;
        ptr = new int[size];
        for(int i = 0; i < size; i++){
            ptr[i] = right.ptr[i];
        }
    }
    return * this;
}

void Object::deleteEndNode(int val){
    Node * curr = nullptr;
    Node * prev = nullptr;
    int size = 0, node = 0;

    if(!head){
        cout << "List is empty" << endl;
    }
    
    curr = head;
    while(curr){
        size++;
        curr = curr->next;
    }
    curr = head;

    node = (size + 1) - val;
    
    for(int i = 0; i < node; i++){
        prev = curr;
        curr = curr->next;
    }
    if(curr){
        prev->next = curr->next;
        delete curr;
    }
}

void Object::findMiddle(){
    Node * curr = nullptr;
    int size = 0, middle = 0; 

    if(!head){
        cout << "List is empty" << endl;
    }
    else{
        curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }
        curr = head;

        if(middle % 2 == 0){
            middle = size / 2;
        }
        else{
            middle = size / 2 + 1;
        }

        for(int i = 0; i < middle; i++){
            curr = curr->next;
        }
        
        cout << "The middle node is: " << curr->value << endl;
    }
}

void Object::deleteTarget(int val){
    Node * curr = nullptr;
    Node * prev = nullptr;

    if(!head){
        cout << "List is empty" << endl;
    }
    else{
        while(head->value == val){
            curr = head->next;
            delete head;
            head = curr;
        }
        curr = head;
        while(curr){
            if(curr->value == val){
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void Object::deleteDup(){
    Node * curr = nullptr;
    Node * next = nullptr;

    if(!head){
        cout << "List is empty" << endl;
    }
    else{
        curr = head;
        while(curr->next != nullptr){
            if(curr->value == curr->next->value){
                if(curr->next->next){
                    next = curr->next->next;
                }
                else{
                    next = nullptr;
                }
                delete curr->next;
                curr = next;
            }
            else{
                curr = curr->next;
            }
        }
    }
}

void Object::reverse(){
    Node * curr = nullptr;
    Node * prev = nullptr;
    Node * next = nullptr;

    if(!head){
        cout << "List is empty" << endl;
    }
    else{
        curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
}