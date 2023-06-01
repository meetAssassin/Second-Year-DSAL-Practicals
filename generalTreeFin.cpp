#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    char title[10];
    int chapCount;
    struct Node *child[10];
} *root;

class generalTree {
    public:

    void createTree(){
        int books;
        int chapterNum;
        root = new Node;
        
        cout << "Enter name of the book: ";
        cin >> root -> title;

        cout << "Enter number of chapters: ";
        cin >> root -> chapCount;
        // root -> chapCount = chapterNum;

        for(int i = 0; i < root -> chapCount; i++){
            root -> child[i] = new Node;
            
            cout << "Enter chapter name: ";
            cin >> root -> child[i] -> title;

            cout << "Enter number of sections in the Chapter " << root -> child[i] -> title << ": ";
            cin >> root -> child[i] -> chapCount;
            // root -> child[i] -> chapCount = chapterNum;

            for(int j = 0; j < root -> child[i] -> chapCount; j++){
                root -> child[i] -> child[j] = new Node;
                cout << "Enter section " << j+1 << "  name: ";
                cin >> root -> child[i] -> child[j] -> title;
            }
        }
    }

    void display(Node *root){
        if(root != NULL){
            cout << "Book Title: " << root -> title << endl;
            for(int i = 0; i < (root -> chapCount); i++){
                cout << "Chapter No: " << i+1 << " is :- " << root -> child[i] -> title << endl;
                for(int j = 0; j < (root -> child[i] -> chapCount); j++){
                    cout << "Section No: " << j+1 << " is:- " << root -> child[i] -> child[j] -> title << endl;
                }
            }
        }
    }
};

int main() {
    generalTree book;

    int choice;
    bool ans = true;
    while(ans){
        cout << "\nMENU\n" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                book.createTree();
                break;

            case 2:
                book.display(root);
                break;

            case 3:
                ans = false;

            default:
                cout << "Invalid Choice" << endl;
        }
    }
    // book.createTree();
    // cout << "\nDisplay\n" << endl;
    // book.display(root);
}