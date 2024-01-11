#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
//printing linked list
void printLinkedList(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    //create a list
    Node* head = new Node(10);
    Node* second = new Node(15);
    Node* tail = new Node(20);

    head->next = second;
    second->next = tail;

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}