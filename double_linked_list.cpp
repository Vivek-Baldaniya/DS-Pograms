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
        cout << "\nList data are::";
        while (trv_ptr->next != NULL)
        {
            cout<<endl<<trv_ptr->data;
            trv_ptr = trv_ptr->next;
        }
        cout<<endl<<trv_ptr->data;
    }
    void insert_node(int data){
        node *new_node = new node(data);
        node *trv_ptr = this;
        while (trv_ptr->next != NULL)
        {
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->next = new_node;
        new_node->pre = trv_ptr;
        cout << "\nNode inserted successfully";
    }
    //done by vivek-21CP314
    void update_node(int old_data, int new_data){
        node *trv_ptr = this;
        while (trv_ptr->next != NULL && trv_ptr->data != old_data){
            trv_ptr = trv_ptr->next;
        }
        trv_ptr->data = new_data;
        cout << "\nNode updated successfully.";
    }
    void delete_node(int n){
        node *trv_ptr = this;
        while (trv_ptr->next != NULL && trv_ptr->data != n){
            trv_ptr = trv_ptr->next;
        }
        if(trv_ptr->next != NULL){
            trv_ptr->pre->next = trv_ptr->next;
            trv_ptr->next->pre = trv_ptr->pre;
        }else{
            trv_ptr->pre->next = NULL;
        }
        cout << "\nNode deleted successfully";
    }
};

int main(){
    int n;
    node *first = new node(5);
    node *new_node = new node();
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
                        first = first->next;
                        first->pre = NULL;
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
                    new_node->data = new_data;
                    first->pre = new_node;
                    new_node->next = first;
                    first = new_node;
                    first->traverse();
                    break;
            default: cout<<"\nSelect valid operation";
                    break;
        }
    }
}