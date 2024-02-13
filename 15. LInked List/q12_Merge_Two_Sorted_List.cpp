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

//Time = O(n) , Space = O(1) where n = total length after merge
Node* mergeTwoLists(Node* left, Node* right) {
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node* ansHead = new Node(-1);
    Node* temp = ansHead;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if(left != NULL){
        temp->next = left;
    }
    if(right != NULL){
        temp->next = right;
    }

    //free the -1 node
    Node* varNode = ansHead;
    ansHead = ansHead->next;
    varNode->next = NULL;
    delete varNode;

    return ansHead;
}
int main(){
    Node* headA = new Node(1);
    Node* second1 = new Node(3);
    Node* third1 = new Node(5);
    headA->next = second1;
    second1->next = third1;

    Node* headB = new Node(2);
    Node* second2 = new Node(4);
    Node* third2 = new Node(5);
    headB->next = second2;
    second2->next = third2;

    Node* newHead = mergeTwoLists(headA,headB);
    printLinkedList(newHead);
    return 0;
}