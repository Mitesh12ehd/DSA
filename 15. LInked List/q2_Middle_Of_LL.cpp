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
    ~Node(){
        //here we have to destructor
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

//time = O(n/2) = O(n)  space = O(1)
Node* getMiddle(Node*& head){
    if(head == NULL){
        cout << "linked list empty";
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main(){
    //create a linked list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = fifth;

    Node* middle = getMiddle(head);
    cout<< middle->data << endl;
    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}