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
        //here we have to right constructor
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};

//printing linked list
void printLinkedList(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//find length of linked list
int findlength_Of_LinkedList(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//insert at head , starting of linked list
void insertAtHead(Node*& head,Node*& tail,int data){
    //step 1
    Node* newNode = new Node(data);
    //step 2
    if(head == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    //step 3
    newNode->next = head;
    //step 4
    head = newNode;
}

//insert at tail, ending of linked list
void insertAtTail(Node*& head,Node*& tail,int data){
    //step 1
    Node* newNode = new Node(data);
    //step 2
    if(head == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    //step 3
    tail->next = newNode;
    tail = newNode;
}

//insert after particular position
void insertAtPosition(Node*& head,Node*& tail,int position,int data){
    //step 1
    if(position == 0){
        insertAtHead(head,tail,data);
        return;
    }
    //step 2
    int len = findlength_Of_LinkedList(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }
    //step 3
    Node* newNode = new Node(data);
    //step 4
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    //step 5
    int i=1;
    Node* prevNode = head;
    while(i<position){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;
    //step 6
    newNode->next = currNode;
    prevNode->next = newNode;
}

//delete first node -- head node
void deleteHead(Node*& head, Node*& tail){
    //step 1
    if(head == NULL){
        cout << "can not delete , list is already empty";
        return;
    }
    //step 2
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

//delete last node -- tail node
void deleteTail(Node*& head, Node*& tail){
    //step 1
    if(head==NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //step 2
    int len =  findlength_Of_LinkedList(head);
    //step 3
    if(len == 1){
        deleteHead(head,tail);
        return;
    }
    //step 4
    int i=1;
    Node* prevNode = head;
    while(i < len-1){
        prevNode = prevNode->next;
        i++;
    }
    //step 5
    prevNode->next = NULL;
    Node* temp = tail;
    tail = prevNode;
    delete temp;
}

//delete at position
void deleteAtPosition(Node*& head, Node*& tail,int position){
    //step 1
    if(head == NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //step 2
    if(position == 1){
        deleteHead(head,tail);
        return;
    }
    //step 3
    int len = findlength_Of_LinkedList(head);
    if(position >= len){
        deleteTail(head,tail);
        return;
    }
    //step 4
    int i=1;
    Node* prevNode = head;
    while(i < position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;
    //step 5
    prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;
}

//recursive
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
//iterative
Node* reverseLL(Node*& head){
    Node* prevNode = NULL;
    Node* currNode = head;
    while(currNode != NULL){
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
int main(){
    //create a list
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);

    Node* prevNode = NULL;
    Node* currNode = head;
    //recursive
    // head = reverseLL(prevNode,currNode);
    //iterative
    head = reverseLL(head);

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}