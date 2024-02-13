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

//1. print linked list Time = O(n) , Space = O(1)
void printLL(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

//2. find length of linked list Time = O(n) , Space = O(1)
int findLength(Node*& head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//3.insert at head Time = O(1) , Space = O(1)
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

//4. insert at tail Time = O(1) , Space = O(1)
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

//5. insert after given position Time=O(n),space=O(1)
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
    //find prevNode and nextNode
    int i=1;
    Node* prevNode = head;
    while(i<position){
        prevNode = prevNode->next;
        i++;
    }
    Node* nextNode = prevNode->next;

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

//6. delete head
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

//7. delete tail
void deleteTail(Node*& head,Node*& tail){
    if(head == NULL){
        cout<<"can not delete,list is already empty";
        return;
    }
    //check if there is one node in list
    int len = findLength(head);
    if(len == 1){
        deleteHead(head,tail);
        return;
    }

    //here we not have to travese and find prev ,
    //because we have access to prev pointer directly
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    delete temp;
}

//8. delete given position node
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

    //find prevNode,currNode,nextNode
    int i=1;
    Node* prevNode = head;
    while(i < position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;
    Node* nextNode = currNode->next;

    //operation
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    currNode->prev = NULL;
    currNode->next = NULL;
    delete currNode;

}

//9. insert after given value
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
    newNode->prev = prevNode;
    prevNode->next = newNode;
    currNode->prev = newNode;
}

//10. delete node with given value
void DeleteNodeWithValue(Node*& head,Node*& tail,int value){
    //check if list is empty
    if(head == NULL){
        cout << "can not delete , list is already empty" <<endl;
        return;
    }
    //check if first node is value or not
    if(head->data == value){
        deleteHead(head,tail);
        return;
    }
    //find prevNode and currNode
    Node* prevNode = head;
    while(prevNode->next != NULL){
        if(prevNode->next->data == value){
            break;
        }
        else{
            prevNode = prevNode->next;
        }
    }
    //if value not found
    if(prevNode->next == NULL){
        cout << "value not found"<<endl;
        return;
    }

    //find curr node ,nextNode and operation
    Node* currNode = prevNode->next;
    Node* nextNode = currNode->next;
    prevNode->next = currNode->next;
    nextNode->prev = prevNode;
    currNode->next = NULL;
    currNode->prev = NULL;
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
    // insertAtTail(head,tail,60);
    // insertAtPosition(head,tail,15,3);
    // insertAfterValue(head,tail,20,60);

    // deleteHead(head,tail);
    // deleteTail(head,tail);
    // deleteAtPosition(head,tail,1);
    DeleteNodeWithValue(head,tail,10);

    printLL(head);
    return 0;
}