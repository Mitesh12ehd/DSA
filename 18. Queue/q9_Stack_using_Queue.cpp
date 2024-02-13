#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//method 1 : using 2 queue
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() {
        int poppedElement = q1.front();
        q1.pop();
        return poppedElement;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

//method 2 : using 1 queue
class MyStack {
public:  
    queue<int> q;
    MyStack() {
        
    }
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    int pop() {
        int poppedElement = q.front();
        q.pop();
        return poppedElement;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};