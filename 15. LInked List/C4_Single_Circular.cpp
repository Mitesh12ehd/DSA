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
        //here we have to write destructor
        cout << "Node with value = "<< this->data << " is deleted" <<endl;
    }
};

//1. print LL
void printLL(Node*& start){
    if(start == NULL){
        cout << "list is empty";
        return;
    }

    Node* temp = start;
    cout << temp->data << " ";
    temp = temp->next;

    while(temp != start){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

//2. find length
int findLength(Node*& first){
    int len = 0;
    Node* temp = first;
    len++;
    temp = temp->next;
    while(temp != first){
        len++;
        temp = temp->next;
    }
    return len;
}

//insert after value
//here we must give value that is present in list
//if it not present it placed radomly;
void insertAfterValue(Node*& first,int value,int data){
    Node* newNode = new Node(data);
    //check if it is first node
    if(first == NULL){
        first = newNode;
        newNode->next = newNode;
        return;
    }

    //find prevNode and nextNode
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
    prevNode->next = newNode;
}

//delete node with given value
void deleteValue(Node*& first,int value){
    //check if list empty
    if(first == NULL){
        cout<< "\n list is already empty";
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
    for(int i=1; i<= len; i++){
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
        currNode->next = NULL;
        delete currNode;
        first = prevNode->next;
    }
    else{
        prevNode->next = currNode->next;
        currNode->next = NULL;
        delete currNode;
    }
}
int main(){
    //code to manually create circular single linked list
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // first->next = second;
    // second->next = third;
    // third->next = first;
    // print(first);
    // cout <<endl;
    // cout <<findLength(first);

    Node* first = NULL;
    insertAfterValue(first,100,10);
    insertAfterValue(first,10,20);
    insertAfterValue(first,20,30);
    insertAfterValue(first,30,40);
    // insertAfterValue(first,10,20);
    // insertAfterValue(first,20,30);
    // insertAfterValue(first,30,40);
    // insertAfterValue(first,40,73);

    // deleteValue(first,10);

    printLL(first);

    return 0;
}