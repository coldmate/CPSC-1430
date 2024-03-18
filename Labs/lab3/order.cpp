// Alen Ovalles
// order.cpp
// Purpose: Implementing an Order class Objectives
// Input: none
// Processing: calls setter fuctions, sets a object member variables
// Output: calls getter functions, prints message when a fucntion is being called
// Examples: Order consumer;
//
//           cout << "Consumer name is being set..." << endl;
//           consumer.setName("Bob");
//           
//           cout << "Consumer Name: " << consumer.getName() << endl;
//             

#include <iostream>
#include <iomanip>

using namespace std;

class Order{
    private: // memeber variables
        string name;
        int itemID;
        double total;
        bool status;
    public: 
        // setter functions
        void setName(string n);
        void setItemID(int i);
        void setTotal(double t);
        void setStatus(bool s);

        // getter functions
        string getName(){return name;}
        int getItemID(){return itemID;}
        double getTotal(){return total;}
        bool getStatus(){return status;}
};

void Order::setName(string n){
    name = n;
}
void Order::setItemID(int i){
    itemID = i;
}
void Order::setTotal(double t){
    total = t;
}
void Order::setStatus(bool s){
    status = s;
}

int main() {
    Order customer;

    cout << endl;
    cout << "Name is being set..." << endl;
    customer.setName("Alen Ovalles");

    cout << "ItemID is being set..." << endl;
    customer.setItemID(9);

    cout << "Total is being set..." << endl;
    customer.setTotal(10.00);

    cout << "Status is being set..." << endl << endl;
    customer.setStatus(true);
    
    cout << "********CUSTOMER'S ORDER********" << endl;
    cout << "Name: " << customer.getName() << endl;
    cout << "ItemID: " << setfill('0') << setw(2) << customer.getItemID() << endl;
    cout << "Total: " << setprecision(2) << fixed << customer.getTotal() << endl;

    if(customer.getStatus() == 1){  
        cout << "Status: Active" << endl; // status == true
    }
    else{
        cout << "Status: Inactive" << endl; // status == false
    }
    
    cout << endl;
    
}
