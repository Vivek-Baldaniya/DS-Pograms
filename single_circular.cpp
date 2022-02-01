#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
    node(){
        data = 0;
        next = NULL;
    }
    node(int n){
        data = n;
        next = NULL;
    }
    void traverse(){
        node *trv_ptr = this;
        cout << "\nList data are::";
        while (trv_ptr->next != this)
        {
            cout<<endl<<trv_ptr->data;
            trv_ptr = trv_ptr->next;
        }
        cout<<endl<<trv_ptr->data;
    }
    void insert_node(int data){
        node *new_node = new node(data);
        node *trv_ptr = this;
        if(this->next != NULL){
            while (trv_ptr->next != this)
            {
                trv_ptr = trv_ptr->next;
            }
        }
        trv_ptr->next = new_node;
        new_node->next = this;
        cout << "\nNode inserted successfully";
    }
    void insert_first_node(node **first, int data){
        node *trv_ptr = this;
        node *new_node = new node(data);
        while (trv_ptr->next != this){
            trv_ptr = trv_ptr->next;
        }
        new_node->next = *first;
        trv_ptr->next = new_node;
        *first = new_node;
    }
    //done by vivek-21CP314
    void update_node(int old_data, int new_data){
        node *trv_ptr = this;
        while (trv_ptr->next != this && trv_ptr->data != old_data){
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->data = new_data;
        cout << "\nNode updated successfully.";
    }
    void delete_node(int n){
        node *trv_ptr = this;
        node *pre_ptr = NULL;
        while (trv_ptr->next != this && trv_ptr->data != n){
            pre_ptr = trv_ptr;
            trv_ptr = trv_ptr->next;
        }
        pre_ptr->next = trv_ptr->next;
        cout << "\nNode deleted successfully";
    }
    void delete_first_node(node **first){
        node *trv_ptr = this;
        while (trv_ptr->next != this){
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next = this->next;
        *first = trv_ptr->next;
        cout << "\nNode deleted successfully";
    }
};

int main(){
    int n;
    
    node *first = new node(5);
    int new_data, old_data;
    
    while (1){
        int input;
        cout << "\nPress 1 to insert node::";
        cout << "\nPress 2 to update node::";
        cout << "\nPress 3 to delete node::";
        cout << "\nPress 4 to view all data::";
        cout << "\nPress 5 to insert node at first::";
        cin >> input;
        switch (input){
            case 1: cout << "\nEnter data to insert::";
                    cin >> new_data;
                    first->insert_node(new_data);
                    cout << "\nNow list is::";
                    first->traverse();
                    break;
            case 2: cout << "\nEnter data to update::";
                    cin >> old_data;
                    cout << "Enter new data to replace with::";
                    cin >> new_data;
                    first->update_node(old_data, new_data);
                    cout << "\nNow list is::";
                    first->traverse();
                    break;
            case 3: cout << "\nEnter data to delete from list::";
                    cin >> new_data;
                    if(new_data == first->data){
                        first->delete_first_node(&first);
                    }
                    else{
                        first->delete_node(new_data);
                    }
                    cout << "\nNow list is::";
                    first->traverse();
                    break;
            case 4: first->traverse();
                    break;
            case 5: cout<<"\nEnter data::";
                    cin>>new_data;
                    first->insert_first_node(&first, new_data);
                    first->traverse();
                    break;
            default: cout<<"\nSelect valid operation";
                    break;
        }
    }
}