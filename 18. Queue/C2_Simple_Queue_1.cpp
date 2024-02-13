#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "queue is full" <<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout << "queue is empty" << endl;
        }
        else{
            front++;
            if(front == rear){
                //if queue become empty after one deletion start them from 0 index
                front = 0;
                rear = 0;
            }
        }
    }
    
    int getFront(){
        if(front == rear){
            cout << "queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }

    int getSize(){
        return rear-front;
    }
};

int main(){
    Queue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout << "size of queue = " << q.getSize() << endl;

    q.pop();
    q.pop();

    cout << "size of queue = " << q.getSize() <<endl;
    cout << "front element = " << q.getFront() <<endl;

    cout << q.isEmpty() << endl;

    return 0;
}