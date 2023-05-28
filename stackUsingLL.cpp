#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        class Node* next;
};

class Node* top = NULL;

void push(int n){
    Node *newNode = new Node();
    newNode -> data = n;
    newNode -> next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        cout << "Stack Underflow!" << endl;
    } else {
        cout << "Popped element is: " << top -> data << endl;
        top = top -> next;
    }
}

void display(){
    class Node *ptr;
    if(top == NULL){
        cout << "Stack Underflow!" << endl;
    } else {
        ptr = top;
        while(ptr != NULL){
            cout << ptr -> data;
            ptr = ptr -> next;
            cout << endl;
        }
    }
}


int main(){
    int a;
    int n;

    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;

do{
    cout << "Enter a choice: ";
    cin >> a;
    switch (a){
        case 1: {
            cout << "Enter element to be pushed: ";
            cin >> n;
            push(n);
            break;
        }
        
        case 2: {
            pop();
            break;
        }

        case 3: {
            display();
            break;
        }

        case 4: {
            cout << "Exiting..." << endl;
            break;
            return 0;
        }

        default: {
            cout << "Invalid choice.";
            break;
        }
    }

    } while (a != 4);
    return 0;

}