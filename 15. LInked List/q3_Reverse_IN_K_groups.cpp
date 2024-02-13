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

// time = O(n) Space = O(n/k)
Node* reverseLL(Node*& head,int k){
    if(head == NULL){
        cout << "linked list is empty";
        return head;
    };
    int len = findlength_Of_LinkedList(head);
    if(k > len){
        cout << "k must be smaller than length";
        return head;
    }

    //step 1. reverese k node
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode;
    int i=1;
    while(i<=k){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;//increament
        currNode = nextNode;//increament
        i++;
    }

    //step 2. reverese a remain node by rescursion
    if(nextNode != NULL){
        //here we have written head->next beacuse when k node reveresed,
        //head is shifted at the end
        head->next = reverseLL(nextNode,k);
    }

    //step 3. return prevNode
    return prevNode;
}

int main(){
    //create a linked list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    int k = 3;
    head = reverseLL(head,k);

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}