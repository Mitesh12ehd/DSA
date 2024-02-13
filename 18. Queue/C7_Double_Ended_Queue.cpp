#include<iostream>
using namespace std;

class DeQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    DeQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        if(rear == size-1){
            //check queue full
            cout << "queue is full";
        }
        else if(front == -1){
            //handle first insertion
            front = rear = 0;
            arr[rear] = data;
        }
        else{
            //normal flow
            rear++;
            arr[rear] = data;
        }
    }
    void pushFront(int data){
        if(front == 0){
            //check queue full
            cout << "queue is full";
        }
        else if(front == -1){
            //handle first insertion
            front = rear = 0;
            arr[front] = data;
        }
        else{
            //normal flow
            front--;
            arr[front] = data;
        }
    }

    void popFront(){
        if(front == -1){
            cout << "queue is empty";
        }
        else if(front == rear){
            //handle if there is one element
            front = rear = -1;
        }
        else{
            //normal case
            front++;
        }
    }
    void popRear(){
        if(front == -1){
            cout << "queue is empty";
        }
        else if(front == rear){
            //handle if there is one element
            front = rear = -1;
        }
        else{
            //normal case
            rear--;
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    int getSize(){
        return rear-front+1;
    }
};


int main(){
    DeQueue q(5);

    q.pushFront(10);
    q.pushRear(30);
    q.pushRear(40);
    q.pushRear(50);

    cout <<"size = " <<q.getSize() <<endl;

    q.popFront();
    q.popRear();

    cout << "size = " <<q.getSize() << endl;

    return 0;
}