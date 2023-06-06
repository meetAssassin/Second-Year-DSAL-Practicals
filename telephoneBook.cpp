#include <iostream>
using namespace std;

class node {
	string name;
	long int tel;
	// int id;

    public:
        node(){
            tel = 0;
            // id = 0;
        }
        friend class hashing;
};

class hashing {
    node data[100];
	string n;
	long int t;
	// int i; 
    int index;

    public:
	    hashing(){
            // i = 0;
            t = 0;
	    }  
    
    void createRecord(int size) {
        // cout << "Enter ID: ";
        // cin >> i;
        cout << "Enter Name: ";
        cin >> n;
        cout << "Enter Telephone: ";
        cin >> t;

        index = t % size;

        for(int j = 0; j < size; j++) {
            if(data[index].tel == 0) {
                // data[index].id = i;
                data[index].tel = t;
                data[index].name = n;
                break;
              } else {
                index = (index + 1) % size;
              }
        }
    }

    void searchRecord(int size) {
        int index1;
        int key;
        int flag = 0;

        cout << "Enter Telephone Number to search: ";
        cin >> key;
        index1 = key % size;

        for(int j = 0; j < size; j++) {
            if(data[index1].tel == key) {
                flag = 1;
                cout << "Record Found" << endl;
                // cout << "ID: " << data[index1].id << endl;
                cout << "Name: " << data[index1].name << endl;
                cout << "Telephone: " << data[index1].tel << endl;
                break;
            } else {
                index1 = (index1 + 1) % size;
            }
            if(flag == 0) {
                cout << "Record Not Found" << endl;
            }
        }
    }

    void deleteRecord(int size) {
        int index1;
        int key;
        int flag = 0;

        cout << "Enter ID to be deleted: ";
        cin >> key;
        index1 = key % size;

        for(int j = 0; j < size; j++) {
            if(data[index1].tel == key) {
                flag = 1;
                // data[index1].id = 0;
                data[index1].tel = 0;
                data[index1].name = " ";
                cout << "Record deleted sucessfully" << endl;
                break;
            } else {
                index1= (index1 + 1) % size;
            }
            if(flag == 0) {
                cout << "Record not found" << endl;
            }
        }
    }

    void displayRecord(int size) {
        cout << "Name \tTelephone" << endl;
        for(int j = 0; j < size; j++){
            if(data[j].tel != 0){
                cout << data[j].name << "\t" << data[j].tel << "\n";
            }
        }
    }
};

int main(){
    int size;
    int choice;

    hashing s;
    bool ans = true;
    while(ans){
        cout << "\nMENU\n" << endl;
        cout << "1. Create Records" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Delete Records" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter size of telephone book: ";
                cin >> size;
                for(int i = 0; i < size; i++){
                    s.createRecord(size);
                }
                break;
            case 2:
                s.displayRecord(size);
                break;
            case 3:
                s.deleteRecord(size);
                break;
            case 4:
                ans = false;
        }
    }
    

    // cout << "Creating records" << endl;
    // s.createRecord(size);
    // s.createRecord(size);
    // s.createRecord(size);

    // cout << "Display records" << endl;
    // s.displayRecord(size);

    // cout << "Search" << endl;
    // s.searchRecord(size);

    // cout << "Delete Record" << endl;
    // s.deleteRecord(size);
}