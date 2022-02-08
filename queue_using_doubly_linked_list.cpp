#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
    node *pre;
    node(){
        data = 0;
        next = NULL;
        pre = NULL;
    }
    node(int n){
        data = n;
        next = NULL;
        pre = NULL;
    }
    void traverse(){
        node *trv_ptr = this;
        cout << "\nQueue data are::";
        while (trv_ptr->next != NULL){
            cout<<endl<<trv_ptr->data;
            trv_ptr = trv_ptr->next;
        }
        cout<<endl<<trv_ptr->data;
    }
    void insert_node(node **rear, int data){
        node *new_node = new node(data);
        new_node->pre = *rear;
        this->next = new_node;
        *rear = new_node;
        cout << "\nNode inserted successfully";
    }
    //done by vivek-21CP314
    void delete_node(node **front){
        *front = this->next;
        cout << "\nNode deleted successfully";
    }
};

int main(){
    node *front = new node(5);
    node *rear = new node(10);
    front->next = rear;
    rear->pre = front;
    int new_data;
    
    while (1){
        int input;
        cout << "\nPress 1 to insert data::";
        cout << "\nPress 2 to delete data::";
        cout << "\nPress 3 to view all data::";
        cin >> input;
        switch (input){
            case 1: cout << "\nEnter data to insert::";
                    cin >> new_data;
                    if(rear == 0)
                        front = rear = new node(new_data);
                    else
                        rear->insert_node(&rear, new_data);
                    cout << "\nNow Queue is::";
                    front->traverse();
                    break;
            case 2: if(front == rear){
                        front = rear = 0;
                        cout<<"Queue is Empty.";
                    }
                    else{
                        front->delete_node(&front);
                        cout << "\nNow Queue is::";
                        front->traverse();
                    }
                    break;
            case 3: if(front == 0)
                        cout<<"Queue is empty.";
                    else
                        front->traverse();
                    break;
            default: cout<<"\nSelect valid operation";
                    break;
        }
    }
}