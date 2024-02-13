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
void linkdelete(Node*& head, int M, int N){
    if(head == NULL){
        return;
    }

    //skip m nodes
    Node* it = head;
    for(int i=1; i<=M-1; i++){
        //if M nodes are not available
        if(it == NULL){
            return;
        }
        it = it->next;
    }
    //now temp is stand at m'th node
    if(it == NULL){
        return;
    }
    Node *Mthnode = it;
    it = it->next;
    //delete n node
    for(int i=1; i<=N; i++){
        if(it == NULL){
            break;
        }
        Node* temp = it;
        it = it->next;
        delete temp;
    }
    Mthnode->next = it;

    //recursive call
    linkdelete(it,M,N);
}
int main(){
    Node* head = new Node(9);
    Node* second = new Node(1);
    Node* third = new Node(3);
    Node* fourth = new Node(5);
    Node* fifth = new Node(9);
    Node* sixth = new Node(4);
    Node* seventh = new Node(10);
    Node* eigth = new Node(1);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    
    linkdelete(head,2,1);
    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}