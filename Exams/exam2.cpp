#include <iostream>
using namespace std;

// FOR LINKED LIST EXAM
// DISMISS ERRORS
// BROKEN CODE
// ALL FROM MEMORY | NO HELP

/*
    if(!l1Head && !l2Head){
        return nullptr;
    }
    if(!l1Head){
        return l2Head;
    }
    if(!l2Head){
        return l1Head;
    }

    if(l1Head->value < l2Head->value){
        l1Head->next = mergeList(l1Head->next, l2Head);
        return l1Head;
    }
    else{
        l2Head->next = mergeList(l1Head, l2Head->next);
        return l2Head;
    }
    */

class Object{
    private:
        struct List{
            int value;
            List * next;
        } 
        List * head;
    public:
        Object();
        ~Object();
        void append(int);
        void insert(int);
        void deleteNum(int);
        void display() const;

        void reverse();
        void deleteNodeEnd(int);
        void findMiddle();
        void deleteTargets(int);
        void deleteDups(int num);
};

Object::Object(){
    head = nullptr;
}

Object::~Object(){
    List * curr = nullptr;
    List * next = nullptr;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }
}

void Object::append(int  num){
    List * curr = nullptr;
    List * prev = nullptr;
    List * newNode = nullptr;

    newNode = new List;
    newNode->value = num;
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

void Object::insert(int num){
    List * curr = nullptr;
    List * prev = nullptr;
    List * newNode = nullptr;

    newNode = new List;
    newNode->value = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    }
    else{
        curr = head;
        while(curr != nullptr && curr->value < num){
            prev = curr;
            curr = curr->next;
        }
        if(!prev){
            head = newNode;
            newNode->next = curr;
        }
        else{
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void Object::deleteNum(int num){
    List * curr = nullptr;
    List * prev = nullptr;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr != nullptr && curr->value != num){
            prev = curr;
            curr = curr->next;
        }
        if(curr){
            prev->next = curr->next;
            delete curr;
            curr = prev;
        }
    }
}

void Object::display() const{
    List * curr = nullptr;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            cout << curr->value << endl;
            curr = curr->next;
        }
    }
}

void Object::reverse(){
    List * curr = nullptr;
    List * prev = nullptr;
    List * next = nullptr;

    if(!head){
        return;
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

void Object::deleteNodeEnd(int num){
    List * curr = nullptr;
    List * prev = nullptr;
    int node, counter = 0;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            counter++;
            curr = curr->next;
        }
        curr = head;
        node = counter - num;
        if(node == 0){
            node++;
        }
        for(int i = 0; i < node; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        curr = prev;
    }
}

void Object::findMiddle(){
    List * curr = nullptr;
    int middle, counter = 0;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            counter++;
            curr = curr->next;
        }
        curr = head;
        if(counter == 1){
            middle = counter;
        }
        else if(counter % 2 == 0){
            middle = counter / 2;
        }
        else(
            middle = (counter / 2) + 1;
        )
        for(int i = 0; i < middle; i++){
            curr = curr->next;
        }
    }
    cout << curr->value << " is the middle value" << endl;
}

void Object::deleteTargets(int num){
    List * curr = nullptr;
    List * prev = nullptr;
    
    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            if(curr->value == num){
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            prev = curr;
            curr =  curr->next;
        }
    }
}

void Object::deleteDups(int num){
    List * curr = nullptr;
    List * prev = nullptr;

    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            if(prev->value == curr->value){
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}