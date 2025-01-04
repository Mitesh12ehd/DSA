#include<iostream>
using namespace std;

class Queue{
    public:

    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    Queue(int n,int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freespot = 0;
    }

    void push(int data , int qn){
        //1. check overflow
        if(freespot == -1){
            cout << "no space in array";
            return;
        }
        //2.find index to insert element
        int index = freespot;
        //3.update freespot
        freespot = next[index];
        //4.
        if(front[qn-1] == -1){
            //first insertion in queue
            front[qn-1] = index;
        }
        else{
            //link new element to prev element
            next[rear[qn-1]] = index;
        }

        //5.update next 
        next[index] = -1;
        //6.increament rear
        rear[qn-1] = index;
        //7.insert element
        arr[index] = data;
    }

    int pop(int qn){
        //1.check underflow
        if(front[qn-1] == -1){
            cout << "queue is empty";
            return -1;
        }
        //2.find index to pop
        int index = front[qn-1];
        //3.increament front
        front[qn-1] = next[index];
        //4.manage freeslot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main(){

    //dry run this example
    Queue q(10,3);

    q.push(7,3);
    q.push(8,3);
    q.push(11,1);
    q.push(12,3);
    q.push(17,1);
    q.push(20,1);

    cout << q.pop(3) << endl;
    cout << q.pop(3) << endl;
    cout << q.pop(1) << endl;

    return 0;
}