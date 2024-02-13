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
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        cout << "node with data " << this->data << " is deleted\n";
    }
};

int findLength(Node*& first){
    if(first == NULL){
        cout << "\n list is empty";
        return 0;
    }
    int len = 0;
    Node* temp = first;
    do{
        len++;
        temp = temp->next;
    }
    while(temp != first);
    return len;
}

void printLL(Node*& first){
    Node* temp = first;
    int len = findLength(first);
    for(int i=1; i<=len; i++){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

void insertAfterValue(Node*& first,int value,int data){
    Node* newNode = new Node(data);
    if(first == NULL){
        first = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        return;
    }

    //find prevNode and nextnode
    int len = findLength(first);
    Node* prevNode = first;
    for(int i=1; i<=len-1; i++){
        if(prevNode->data == value){
            break;
        }
        else{
            prevNode = prevNode->next;
        }
    }

    Node* nextNode = prevNode->next;
    newNode->next = nextNode;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;
}

void deleteNodeWithValue(Node*& first,int value){
    if(first == NULL){
        cout << "\nlist is alreaady empty\n";
        return;
    }
    //check if there is one node in list
    if(first->next == first){
        if(first->data == value){
            first->next = NULL;
            delete first;
            first = NULL;
        }
        else{
            cout <<"node with given value not present\n";
        }
        return;
    }

    int len = findLength(first);
    bool valueFound = false;
    Node* prevNode = first;
    for(int i=1; i<=len; i++){
        if(prevNode->next->data == value){
            valueFound = true;
            break;
        }
        else{
            prevNode = prevNode->next;
        }
    }

    if(!valueFound){
        cout << "node with given value not present\n";
        return;
    }
    //perform operation
    Node* currNode = prevNode->next;
    if(currNode == first){
        //if first node is deleted then we have to update first pointer
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        delete currNode;
        first = prevNode->next;
    }
    else{
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }
}

int main(){
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // first->next = second;
    // first->prev = third;
    // second->next = third;
    // second->prev = first;
    // third->next = first;
    // third->prev = second;
    // printLL(first);

    Node* first = NULL;
    insertAfterValue(first,100,10);
    insertAfterValue(first,10,20);
    insertAfterValue(first,20,30);
    insertAfterValue(first,30,40);

    deleteNodeWithValue(first,1000);

    printLL(first);
    return 0;
}