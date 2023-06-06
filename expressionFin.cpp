#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

class Tree{
    public:
        char prefix[20];
        Node *top;

        void create(char prefix[]){
            stack <Node*> s;
            Node *t1 = new Node;
            Node *t2 = new Node;
            int len = strlen(prefix);

            for(int i=len-1; i>=0; i--){
                top = new Node;
                top -> left = NULL;
                top -> right = NULL;
                if(isalpha(prefix[i])){
                    top -> data = prefix[i];
                    s.push(top);
                } else if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/'){
                    t2 = s.top();
                    s.pop();
                    t1 = s.top();
                    s.pop();
                    top -> data = prefix[i];
                    top -> left = t2;
                    top -> right = t1;
                    s.push(top);
                    
                }
            }
            top = s.top();
            s.pop();
        }

        void display(Node *root){
            if(root != NULL){
                cout << root -> data;
                display(root -> left);
                display(root -> right);
            }
        }

        void postorder(Node *top){
            stack <Node*> s1;
            stack <Node*> s2;
            Node *T = top;
            cout << "Post Order Traversal: ";
            
            s1.push(T);
            while(!s1.empty()){
                T = s1.top();
                s1.pop();
                s2.push(T);
                if(T -> left != NULL){
                    s1.push(T -> left);
                } 
                if(T -> right != NULL){
                    s1.push(T -> right);
                }
            }
            while(!s2.empty()){
                top = s2.top();
                s2.pop();
                cout << top -> data;
            }
        }

        void del(Node *node){
            if(node == NULL){
                return;
            } 
            del(node -> left);
            del(node -> right);
            cout << "Deleting Node: " << node -> data << endl;
            free(node);
        }
};

int main(){
    char expr[20];
    Tree n;
    cout << "Enter prefix expression: ";
    cin >> expr;
    n.create(expr);
    n.display(n.top);
    cout << endl;
    cout << n.top -> data << endl;
    n.postorder(n.top);
    cout << endl;
    n.del(n.top);
    // n.display(n.top);
}