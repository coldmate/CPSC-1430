/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 71***********/
#include "Helper.h"
using namespace std;

//Merge two sorted linked lists in place for task I
Node * mergeList(Node * l1Head, Node * l2Head);
//Removes all the nodes in a sorted list that have the targeted value
Node * removeTargets(Node * head, int val);
//Remove duplicatesd nodes such that node with the same value only appears once
Node * removeDuplicates(Node * head);
//Find the middle node in a given linked list
Node * findMiddle(Node * head);

//Your program will be tested with the following command:
//./lab7_8 test_case.txt NUMBER_HERE(Replace with real number),
//where lab7_8 is your executable name after compilation, 
//test_case.txt is a txt file that has two lines of numbers for creating two lists,
//NUMBER_HERE is a specific target number for task II.
//Note that (1) NUMBER_HERE can be any number when running the command.
//For example, a real command in practice could be "./lab7_8 test_case.txt 6".
//(2) lines could be empty in test_case.txt, which means empty list could be created
int main(int argc, char * argv[]){
    //Preparation. I get this done so that you can focus on the following three tasks.
    //create a list using the first line in the input file
    Node * l1Head = createListFromFile(argv[1], 1);
    //create a list using the second line in the input file
    Node * l2Head = createListFromFile(argv[1], 2);
    //printList(l1Head);
    //printList(l2Head);

    //Your task I: merge the above two sorted lists and keep the merged list sorted.
    //the merge should be in-place. That is, you are not allowed to create a new list,
    //in which node values are copied from two given lists.
    //Instead, you should change the pointers of each existing node properly 
    //to chain the existing nodes in both lists together.
    Node * listHeadAfterTaskI = mergeList(l1Head, l2Head);
    printList(listHeadAfterTaskI);

    //Your task II: find the middle node in the linked list generated after task I
    //If there are two middle nodes, return the first middle nodes.
    //For example, if the list is head->1->2->3->null, the middle node will be 2;
    //if the list is head->1->2->3->4->null, there are will be two middle 
    //nodes (i.e., 2 and 3), your function should return the *first* one, i.e., 2.
    Node * middleNode = findMiddle(listHeadAfterTaskI);
    if (middleNode){
        cout << "The value of the middle node is " << middleNode->value << endl;
    }else{
        cout << "No middle node in an empty list." << endl;
    }

    //Your task III: remove all the nodes in a sorted list that have the targeted value.
    //For example, assuming the targeted value is 6, and the merged list after task I
    //is head->2->2->6->6->7->7->7->7->8->9->null, 
    //after this task III the list will become head->2->2->7->7->7->7->8->9->null
    int targetVal = stoi(argv[2]);
    Node * listHeadAfterTaskIII = removeTargets(listHeadAfterTaskI, targetVal);
    printList(listHeadAfterTaskIII);

    //Your task IV: remove all the duplicated nodes (such that node with the same value
    // only appears once) in the merged list after task III.
    //Since the list remains sorted (non-descending) after task III, 
    //the final list will be strictly ascending as we removed all the duplicated values.
    //Continuing the previous example in taskIII, 
    //if the list returned by taskIII is head->2->2->7->7->7->7->8->9->null,
    //after this taks IV, it will become head->2->7->8->9->null
    Node * listHeadAfterTaskIV = removeDuplicates(listHeadAfterTaskIII);
    printList(listHeadAfterTaskIV);

    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/



/********* YOU SHOULD IMPLEMENT THREE FUNCTIONS AFTER THIS LINE **********/
Node * mergeList(Node * l1Head, Node * l2Head){
    //PUT YOUR CODE HERE FOR TASK I
    Node * ptr1Head = l1Head;
    Node * ptr2Head = l2Head;
    Node * dummy = nullptr;
    int currHead;

    if(!l1Head && !l2Head){
        return dummy;
    }
    if(!l1Head){
        return l2Head;
    }
    if(!l2Head){
        return l1Head;
    }

    if(l1Head->value < l2Head->value){ 
        dummy = l1Head;
        ptr1Head = ptr1Head->next;
        currHead = 1;
    }
    else{
        dummy = l2Head;
        ptr2Head = ptr2Head->next;
        currHead = 0;
    }
    
    while(ptr1Head && ptr2Head){
        if(ptr1Head->value < ptr2Head->value){ 
            dummy->next = ptr1Head;
            dummy = ptr1Head;
            ptr1Head = ptr1Head->next;
        }
        else{ 
            dummy->next = ptr2Head;
            dummy = ptr2Head;
            ptr2Head = ptr2Head->next;
        }
    }

    while(ptr1Head || ptr2Head){
        if(!ptr1Head){
            dummy->next = ptr2Head;
            dummy = ptr2Head;
            ptr2Head = ptr2Head->next;
        }
        else{
            dummy->next = ptr1Head;
            dummy = ptr1Head;
            ptr1Head = ptr1Head->next;
        }
    }   
    
   if(currHead == 1){
       return l1Head;
   }
   else{
       return l2Head;
   }
}

Node * findMiddle(Node * head){
    //PUT YOUR CODE HERE FOR TASK II
    Node * curr = nullptr;
    int middle, counter = 0;

    if(!head){
        return head;
    }
    else{
        curr = head;

        while(curr != nullptr){
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
        else{
            middle = counter / 2;
            middle++;
        }

        for(int i = 1; i < middle; i++){
            curr = curr->next;
        }   
    }
    return curr;
}

Node * removeTargets(Node * head, int val) {
    //PUT YOUR CODE HERE FOR TASK III
    Node * curr = nullptr;
    Node * prev = nullptr;

    if(!head){
        return head;
    }
    else{
        while(head->value == val){
            curr = head->next;
            delete head;
            head = curr;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->value == val){
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

Node * removeDuplicates(Node * head) {
    //PUT YOUR CODE HERE FOR TASK IV
    Node * curr = nullptr;
    Node * next = nullptr;

    if(!head){
        return head;
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
                delete curr-> next;
                curr->next = next;
            }
            else{
                curr = curr->next;
            }
        }
    }
    return head;
}
