#include<iostream>
using namespace std;

//GFG 
//Remove duplicates from sorted doubly linked list

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

Node * removeDuplicates(Node *head){
    int val;
    bool first = true;
        
    Node* temp = head;
    while(temp != NULL){
        if(first){
            val = temp->data;
            first = false;
            temp = temp->next;
        }
        else if(temp->data == val){
            Node* prevNode = temp->prev;
            prevNode->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = prevNode;
            }
            Node* deletedNode = temp;
            temp = temp->next;
                
            deletedNode->next = NULL;
            deletedNode->prev = NULL;
            delete deletedNode;
        }
        else{
            val = temp->data;
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    return 0;
}