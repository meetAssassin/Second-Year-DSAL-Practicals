#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(){
            // data = -1;
            left = NULL;
            right = NULL;
        }

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Tree {
    public:
        Node *root;
        Node *temp;

        void create(){
            int len;
            root = NULL;
            cout << "Enter number of Nodes: ";
            cin >> len; 
            do{
                temp = new Node;
                cout << "Enter data: ";
                cin >> temp -> data;
                temp -> left = NULL;
                temp -> right = NULL;
                if(root == NULL){
                    root = temp;
                } else {
                    insert(root, temp);
                }
                len--;
            } while (len != 0);

        }

        void insert(Node *root, Node *temp){
            if(temp -> data < root -> data){
                if(root -> left == NULL){
                    root -> left = temp;
                } else {
                    insert(root -> left, temp);
                }
            } else if (temp -> data > root -> data){
                if(root -> right == NULL){
                    root -> right = temp;
                } else {
                    insert(root -> right, temp);
                }
            }
        }

        void preorder(Node *root){
            if(root != NULL){
                cout << root -> data << " ";
                preorder(root -> left);
                preorder(root -> right);
            }
        }

        void inorder(Node *root){
            if(root != NULL){
                inorder(root -> left);
                cout << root -> data << " ";
                inorder(root -> right);
            }
        }

        void postorder(Node *root){
            if(root != NULL){
                postorder(root -> left);
                postorder(root -> right);
                cout << root -> data << " ";
            }
        }

        int longestPath(Node *root){
            if(root == NULL){
                return 0;
            } else {
                int leftPath = longestPath(root -> left);
                int rightPath = longestPath(root -> right);
                return max(leftPath, rightPath) +1;
            }
        }

        void minValue(Node *root){
            if(root == NULL){
                cout << "Tree is empty" << endl;
            } else {
                while(root -> left != NULL){
                    root = root -> left;
                }
                cout << "Minimum value in the tree is: " <<  root -> data << endl;
            }
        }

        Node* mirror(Node *root){
            if(root == NULL){
                cout << "ROOT Empty" << endl; 
                return NULL;
            } else {
                Node *temp = root -> left;
                root -> left = root -> right;
                root -> right = temp;
                mirror(root -> left);
                mirror(root -> right);
            }
            return root;
        }

        void search(Node* root, int key){
            bool res = false;
            if(root != NULL){
                if(root -> data == key){
                    res = true;
                    cout << "Data found: " << root -> data << endl;
                } else if(key < root -> data){
                    search(root -> left, key);
                } else {
                    search(root -> right , key);
                }
            }
            if(res == false){
                cout << "Data not found." << endl;
            }
        }
};
    
//        10
//    4        8
// 3     5   7     9    

int main() {
    Tree t1;
    int len;
    // cout << "Enter number of nodes: ";
    // cin >> len;
    bool ans = true;
    int choice;
    while(ans){
        cout << "\tMENU\t" << endl;
        cout << "1. Create Tree" << endl;
        cout << "2. Insert Node" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Minimum Value" << endl;
        cout << "7. lONGEST path" << endl;
        cout << "8. Mirror Tree" << endl;
        cout << "9. Search Tree" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice){
            case 1:
                t1.create();
                break;
            case 2:
                int d;
                cout << "Enter data to insert: ";
                cin >> d;
                Node *temp;
                temp -> data = d;
                t1.insert(t1.root, temp);
                break;
            case 3:
                t1.preorder(t1.root);
                break;
            case 4:
                t1.inorder(t1.root);
                break;
            case 5:
                t1.postorder(t1.root);
                break;
            case 6:
                t1.minValue(t1.root);
                break;
            case 7:
                cout << "Longest Path: " << t1.longestPath(t1.root) << endl;
                break;
            case 8:
                t1.mirror(t1.root);
                break;
            case 9:
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                t1.search(t1.root, key);
        }

    }
    // t1.create();
    // t1.preorder(t1.root);
    // cout << endl;
    // t1.inorder(t1.root);
    // cout << endl;
    // t1.postorder(t1.root);
    // t1.minValue(t1.root);
    // int longest = t1.longestPath(t1.root);
    // cout << "Longest Path: " << longest << endl;

}