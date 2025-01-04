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
// Node* mergeNodes(Node* head) {
//     Node* slow = head;
//     Node* fast = head->next;
//     Node* newLastNode = NULL;
//     int sum = 0;
//     while(fast != NULL){
//         if(fast->data != 0){
//             sum = sum + fast->data;
//         }
//         else{
//             //fast value = 0;
//             slow->data = sum;
//             newLastNode = slow;
//             slow = slow->next;
//             sum = 0;
//         }
//         fast = fast->next;
//     }

//     Node* temp = newLastNode->next;
//     newLastNode->next = NULL;

//     //free memory
//     while(temp != NULL){
//         Node* temp1 = temp;
//         temp = temp->next;
//         delete temp1;
//     }
//     return head;
// }

//my method
Node* mergeNodes(Node* head) {
    //base case
    if(head->next == NULL){
        delete head;
        return NULL;
    }
        
    //delete zero node
    Node* temp = head->next;
    head->next = NULL;
    delete head;

    //count sum and delete nodes
    int sum = 0;
    while(temp->data != 0){
        sum = sum + temp->data;

        //delete node
        Node* dummy = temp;
        temp = temp->next;
        dummy->next = NULL;
        delete dummy;
    }

    //now add sum node
    Node* newNode = new Node(sum);
    newNode->next = temp;

    //recursion
    newNode->next = mergeNodes(temp);

    return newNode;
}

int main(){
    Node* head = new Node(0);
    Node* second = new Node(3);
    Node* third = new Node(1);
    Node* fourth = new Node(0);
    Node* fifth = new Node(4);
    Node* sixth = new Node(5);
    Node* seventh = new Node(2);
    Node* eigth = new Node(0);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    
    head = mergeNodes(head);

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}