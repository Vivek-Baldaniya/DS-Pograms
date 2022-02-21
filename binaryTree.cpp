#include <iostream>

using namespace std;

class node{
    int data;
    node *left;
    node *right;
    public:

        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        void insert_node(node *root, int data){
            node *new_node = new node(data);
            node *trv_ptr = this;
            if(root == NULL){
                root=new_node;
                cout<<"Root Node:"<<root->data;
            }
            else{
                while(trv_ptr != NULL){
                    if(data > trv_ptr->data){
                        if(trv_ptr->right == NULL){
                            trv_ptr->right = new_node;
                            cout<<"\nNode created at right side of its parent node:";
                            break;
                        }
                        trv_ptr = trv_ptr->right;
                    }
                    else if(data < trv_ptr->data){
                        if(trv_ptr->left == NULL){
                            trv_ptr->left = new_node;
                            cout<<"\nNode created at left side of its parent node:";
                            break;
                        }
                        trv_ptr = trv_ptr->left;
                    }
                    else{
                        continue;
                    }
                }
            }
        }

        void inOrder(node *root){
            if (root == NULL) 
                return;
            
            inOrder(root->left);
            cout<<root->data<<"->";
            inOrder(root->right);
        }
        // done by 21CP314-Vivek
        void postOrder(node *root){
            if (root == NULL) 
                return;
            
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<"->";
        }

        void preOrder(node *root){
            if (root == NULL) 
                return;
            
            cout<<root->data<<"->";
            preOrder(root->left);
            preOrder(root->right);
        }

        void searchNode(int n){
            int count=0;
            node *trv_ptr = this;
            while(trv_ptr != NULL){
                count++;
                if(trv_ptr->data == n){
                    cout<<"\nPosition of node "<<trv_ptr->data<<"::"<<count;
                    break;
                }
                else if(n < trv_ptr->data)
                    trv_ptr = trv_ptr->left;
                else
                    trv_ptr = trv_ptr->right;
            }
        }
};

int main(){
    node *root = new node(50);
    int n;

    while(1){
        int input;
        cout << "\nPress 1 to insert data into tree::";
        cout << "\nPress 2 to search the data::";
        cout << "\nPress 3 to in-order traversal::";
        cout << "\nPress 4 to post-order traversal::";
        cout << "\nPress 5 to pre-order traversal::";
        cin >> input;
        switch(input){
            case 1: cout<<"\nEnter Data to insert::";
                    cin>>n;
                    root->insert_node(root, n);
                    break;
            case 2: cout<<"Enter Data to search::";
                    cin>>n;
                    root->searchNode(n);
                    break;
            case 3: root->inOrder(root);
                    cout<<endl;
                    break;
            case 4: root->postOrder(root);
                    cout<<endl;
                    break;
            case 5: root->preOrder(root);
                    cout<<endl;
                    break;
            default: cout<<"Enter valid argument";
                     break;
        }
    }
}