#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        //here we have to write constructor
        int value = this->data;
        cout << "Node with value = "<< value << " is deleted" <<endl;
    }
};

//print linked list Time = O(n) , Space = O(1)
void printLL(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

//find length of linked list Time = O(n) , Space = O(1)
int findLength(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//insert at head Time = O(1) , Space = O(1)
void insertAtHead(Node*& head,Node*& tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//insert at tail Time = O(1) , Space = O(1)
void insertAtTail(Node*& head,Node*& tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

//insert after given position Time=O(n),space=O(1)
void insertAtPosition(Node*& head,Node*& tail,int data,int position){
    if(position == 0){
        insertAtHead(head,tail,data);
        return;
    }
    int len = findLength(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }

    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    int i=1;
    Node* leftNode = head;
    while(i<position){
        leftNode = leftNode->next;
        i++;
    }
    Node* rightNode = leftNode->next;

    leftNode->next = newNode;
    newNode->prev = leftNode;
    newNode->next = rightNode;
    rightNode->prev = newNode;
}

//delete head
void deleteHead(Node*& head, Node*& tail){
    if(head == NULL){
        cout << "can not delete , list is already empty";
        return;
    }
    //if there is one node in list
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}


//delete tail
void deleteTail(Node*& head,Node*& tail){
    if(head == NULL){
        cout<<"can not delete,list is already empty";
        return;
    }
    int len = findLength(head);
    if(len == 1){
        deleteHead(head,tail);
        return;
    }

    //here we not have to travese and find prev ,
    // because we have access to prev pointer directly
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    delete temp;
}

void deleteAtPosition(Node*& head, Node*& tail,int position){
    if(head == NULL){
        cout << "can not delete , list is already empty";
        return;
    }
    if(position == 1){
        deleteHead(head,tail);
        return;
    }
    int len = findLength(head);
    if(position >= len){
        deleteTail(head,tail);
        return;
    }

    //find leftNode,currNode,rightNode
    int i=1;
    Node* leftNode = head;
    while(i < position-1){
        leftNode = leftNode->next;
        i++;
    }
    Node* currNode = leftNode->next;
    Node* rightNode = currNode->next;

    //operation
    leftNode->next = rightNode;
    rightNode->prev = leftNode;
    currNode->prev = NULL;
    currNode->next = NULL;
    delete currNode;

}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtPosition(head,tail,15,3);

    deleteHead(head,tail);
    deleteTail(head,tail);
    deleteAtPosition(head,tail,1);
    
    printLL(head);
    return 0;
}