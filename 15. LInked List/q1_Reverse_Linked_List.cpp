#include<iostream>
using namespace std;

//leetcode 206

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

//recursive Time = O(n) Space = O(n)
// Node* reverseLL(Node*& prevNode,Node*& currNode){
//     //base case
//     if(currNode == NULL){
//         //link list is reversed
//         return prevNode;
//     }

//     Node* nextNode = currNode->next;
//     currNode->next = prevNode;
//     reverseLL(currNode,nextNode);
// }

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
int main(){
    //create a list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = fourth;


    Node* prevNode = NULL;
    Node* currNode = head;
    //recursive
    // head = reverseLL(prevNode,currNode);
    //iterative
    // head = reverseLL(head);

    cout<<"printing linked list" << endl;
    printLinkedList(head);
    return 0;
}