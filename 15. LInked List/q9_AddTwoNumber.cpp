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

//time = O(max(m,n) space = O(1)
Node* solve(Node*& head1,Node*& head2){
    //1.reverse the both list
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    //2.add both linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            //first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //remaining node in list 1
    while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            //first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
    }
    //remaining node in list 2
    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            //first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head2 = head2->next;
    }

    //if carry remaining
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    
    //3.reverse the ans linked list
    ansHead = reverseLL(ansHead);
    return ansHead;
}

int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;

    Node* ansHead = solve(head1,head2);
    printLinkedList(ansHead);
    return 0;
}