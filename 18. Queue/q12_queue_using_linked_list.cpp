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

class CircularQueue{
    private:
    Node* front;
    Node* rear;
    int size;

    public:
    CircularQueue(){
        front = NULL;
        rear = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop(){
        if(front == NULL){
            cout << "queue is empty";
            return;
        }

        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
};

int main(){
    CircularQueue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();
    q.pop();
    
    return 0;
}