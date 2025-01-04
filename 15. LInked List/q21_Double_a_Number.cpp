#include<iostream>
using namespace std;

//leetcode 2816-double a number represnted by linked list

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
        //here we have to right constructor
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};

//iterative Time = O(n) Space = O(1)
Node* reverseLL(Node*& head){
    Node* prevNode = NULL;
    Node* currNode = head;
    while(currNode != NULL){
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;//increament
        currNode = nextNode;//increament
    }
    return prevNode;
}

Node* doubleIt(Node* head){
    //1. reverse the list
    head = reverseLL(head);

    //2.perform multiplication
    Node* temp = head;
    Node* prevNode;
    int carry = 0;
    while(temp != NULL){
        int num = ((temp->data) * 2) + carry;
        int digit = num%10;
        carry = num/10;
        temp->data = digit;

        prevNode = temp;
        temp = temp->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        prevNode->next = newNode;
    }
    
    //3. reverse the list
    head = reverseLL(head);
    return head;
}


int main(){
    return 0;
}