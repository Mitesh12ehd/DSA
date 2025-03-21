#include<iostream>
using namespace std;

//Leetcode 19
//Remove nth node from the end of the list

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
        cout << "Node with value = "<< this->data << " is deleted" <<endl;
    }
};

//brute force time = 2*n
int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
Node* removeNthFromEnd(Node* head, int n) {
    if(head == NULL || n==0){
        return head;
    }

    int len = findlength_Of_LinkedList(head);
    if(len == n){
        head = head->next;
        return head;
    }

    Node* prevNode = head;
    for(int i=1; i<=len-n-1; i++){
        prevNode = prevNode->next;
    }

    Node* currNode = prevNode -> next;
    prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;

    return head;
}

//optimize time n

//we maintain two pointers 
//1.slow and fast (this is not tortois alogrithm)
//2.put both on head
//3.increament fast n time
//4.now increament slow and fast by one step until fast -> next != NULL
//5.at this point slow will stand at previous node of node which we want to delete

Node* removeNthFromEnd(Node* head, int n) {
    Node* slow = head;
    Node* fast = head;

    while(n--){
        fast = fast -> next;
    }

    if(fast == NULL){
        //execute only when nth node from end is head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow->next;
    slow->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main(){
    return 0;
}