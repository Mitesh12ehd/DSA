#include<iostream>
using namespace std;

//Leetcode 61
//Rotate list

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
    ~Node(){
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};
void printLinkedList(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

Node* rotateRight(Node*& head, int k) {
    if(head == NULL){
       return NULL;
    }

    int len = findlength_Of_LinkedList(head);
    int rotateTime = (k%len);
    if(rotateTime == 0){
        return head;
    }

    int i=1;
    Node* temp = head;
    while(i <= len-rotateTime-1){
        temp = temp->next;
        i++;
    }
    Node* newHead = temp->next;
    temp->next = NULL;

    Node* temp1 = newHead;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = head;

    return newHead;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    head = rotateRight(head,2);
    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}