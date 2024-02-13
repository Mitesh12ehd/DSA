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
        cout << "Node with value = "<< this->data << " is deleted" <<endl;
    }
};
void printLL(Node*& start){
    if(start == NULL){
        cout << "list is empty";
        return;
    }
    Node* temp = start;
    do{
        cout << temp->data<<" ";
        temp = temp->next;
    }while(temp != start);
}
int findLength(Node*& first){
    int len = 0;
    Node* temp = first;
    do{
        len++;
        temp = temp->next;
    }while(temp != first);
    return len;
}

//time = O(n) Space = O(1)
bool isCircular(Node*& head){
    Node* temp = head;
    do{
        temp = temp->next;
        if(temp == head){
            return true;
        }
    }while(temp->next != NULL);
    return false;
}

int main(){
    //code to manually create circular single linked list
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    first->next = second;
    second->next = third;
    third->next = first;

    cout << isCircular(first);

    return 0;
}