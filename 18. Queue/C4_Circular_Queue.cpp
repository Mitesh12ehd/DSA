#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if((front == 0 && rear == size-1) || rear == front-1){
            //check queue full
            cout << "queue is full";
        }
        else if(front == -1){
            //handle first insertion
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            //handle circular nature
            rear = 0;
            arr[rear] = data;
        }
        else{
            //normal flow
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        if(front == -1){
            cout << "queue is empty";
        }
        else if(front == rear){
            //handle if there is one element
            front = rear = -1;
        }
        else if(front == size-1){
            //handle circular nature
            front = 0;
        }
        else{
            //normal case
            front++;
        }
    }

    int getFront(){
        if(front == -1){
            cout << "queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    int getSize(){
        if(front < rear){
            return rear-front+1;
        }
        else{
            //size - empty gap between front and rear
            return size-front+rear+1;
        }
    }
};

int main(){
    CircularQueue q(5);
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "size of queue = " << q.getSize() << endl;
    cout << "front element = " << q.getFront() << endl;
    q.pop();
    q.pop();
    
    cout << "size of queue = " << q.getSize() << endl;
    cout << "front element = " << q.getFront() << endl;
    q.push(10);
    q.push(20);
    cout << "size of queue = " << q.getSize() << endl;
    q.push(30);
    return 0;
}