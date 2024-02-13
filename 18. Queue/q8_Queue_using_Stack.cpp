#include<iostream>
#include<stack>
using namespace std;

//method 1
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int poppedElement = -1;
        if(!s1.empty()){
            poppedElement = s1.top();
            s1.pop();
        }
        return poppedElement;
    }
    int peek() {
        if(!s1.empty()){
            return s1.top();
        }
        else{
            return -1;
        }
    }
    bool empty() {
        return s1.empty();
    }
};

//method 2
// class MyQueue {
// public:
//     stack<int> s1;
//     stack<int> s2;
//     MyQueue() {
        
//     }
//     void push(int x) {
//         s1.push(x);
//     }
//     int pop() {
//         int popedElement = -1;
//         if(!s2.empty()){
//             popedElement = s2.top();
//             s2.pop();
//         }
//         else{
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             popedElement = s2.top();
//             s2.pop();
//         }
//         return popedElement;
//     }
//     int peek() {
//         int frontElement = -1;
//         if(!s2.empty()){
//             frontElement = s2.top();
//         }
//         else{
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             frontElement = s2.top();
//         }
//         return frontElement;
//     }
//     bool empty() {
//         return s1.empty() && s2.empty();
//     }
// };