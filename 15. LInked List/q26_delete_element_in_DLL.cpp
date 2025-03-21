#include<iostream>
using namespace std;

//coding ninjas
//Delete all occurrences of a given key in a doubly linked list

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

Node * deleteAllOccurrences(Node* head, int k) {
    if(head == NULL){
        return NULL;
    }

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == k){
            Node* deleteNode = temp;
            temp = temp->next;

            //it is head
            if(deleteNode->prev == NULL){
                head = deleteNode->next;
                deleteNode->next = NULL;
                if(head != NULL){
                    head->prev = NULL;
                }
            }
            //if it is tail
            else if(deleteNode->next == NULL){
                deleteNode->prev->next = NULL;
                deleteNode->prev = NULL;
            }
            else{
                deleteNode->prev->next = deleteNode->next;
                deleteNode->next->prev = deleteNode->prev;
                deleteNode->next = NULL;
                deleteNode->prev = NULL;
            }
            delete deleteNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    return 0;
}