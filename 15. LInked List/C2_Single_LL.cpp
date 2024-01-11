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
    //create a newNode
    Node* newNode = new Node(data);
    //check if list is empty
    if(head == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    //operation
    newNode->next = head;
    head = newNode;
}

//insert at tail, ending of linked list
void insertAtTail(Node*& head,Node*& tail,int data){
    //create a newNode
    Node* newNode = new Node(data);
    //check if list is empty
    if(head == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    //operation
    tail->next = newNode;
    tail = newNode;
}

//insert after particular position
void insertAtPosition(Node*& head,Node*& tail,int position,int data){
    //check if we have to insert at head
    if(position == 0){
        insertAtHead(head,tail,data);
        return;
    }
    //check if we have to insert at tail
    int len = findlength_Of_LinkedList(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }
    //create a newNode
    Node* newNode = new Node(data);
    //check if list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    //find prevNode and currNode
    int i=1;
    Node* prevNode = head;
    while(i<position){
        prevNode = prevNode->next;
        i++;
    }
    Node* currnode = prevNode->next;
    //operation
    newNode->next = currnode;
    prevNode->next = newNode;
}

//delete first node -- head node
void deleteHead(Node*& head, Node*& tail){
    //check if list is already empty
    if(head == NULL){
        cout << "can not delete , list is already empty";
        return;
    }
    //operation
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

//delete last node -- tail node
void deleteTail(Node*& head, Node*& tail){
    //check if list is empty
    if(head==NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //check if there is one node in list
    int len =  findlength_Of_LinkedList(head);
    if(len == 1){
        deleteHead(head,tail);
        return;
    }
    //find prevNode
    int i=1;
    Node* prevNode = head;
    while(i < len-1){
        prevNode = prevNode->next;
        i++;
    }
    //operation
    prevNode->next = NULL;
    Node* temp = tail;
    tail = prevNode;
    delete temp;
}

//delete at position
void deleteAtPosition(Node*& head, Node*& tail,int position){
    //check if list is already empty
    if(head == NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //check if we have to delete head
    if(position == 1){
        deleteHead(head,tail);
        return;
    }
    //check if we have to delete tail
    int len = findlength_Of_LinkedList(head);
    if(position >= len){
        deleteTail(head,tail);
        return;
    }
    //find prevNode and currNode
    int i=1;
    Node* prevNode = head;
    while(i < position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currnode = prevNode->next;
    //operation
    prevNode->next = currnode->next;
    currnode->next = NULL;
    delete currnode;
}

//-----Homework value based insertion and deletion-----

//here linked list must be disticint
void insertAfterValue(Node*& head,Node*& tail,int value,int data){
    //create a newNode
    Node* newNode = new Node(data);
    //check if list is empty
    if(head == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    //find prevNode
    Node* prevNode = head;
    while(prevNode != NULL){
        if(prevNode->data == value){
            break;
        }
        else{
            prevNode = prevNode->next;
        }
    }
    //if node with value not found then insert at tail
    if(prevNode == NULL){
        insertAtTail(head,tail,data);
        return;
    }
    //find currNode and operation
    Node* currNode = prevNode->next;
    newNode->next = currNode;
    prevNode->next = newNode;
}

//delete node with given value
void DeleteNodeWithValue(Node*& head,Node*& tail,int value){
    //check if list is empty
    if(head == NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //find Node with value
}
int main(){
    //create a list
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,5);
    insertAtHead(head,tail,10);
    insertAtTail(head,tail,15);
    insertAtTail(head,tail,20);
    insertAtPosition(head,tail,2,16);
    insertAfterValue(head,tail,5,50);


    // deleteHead(head,tail);
    // deleteHead(head,tail);
    // deleteHead(head,tail);
    // deleteHead(head,tail);
    // deleteHead(head,tail);
    // deleteTail(head,tail);
    // deleteAtPosition(head,tail,3);

    cout<<"printing linked list" << endl;
    printLinkedList(head);

    return 0;
}