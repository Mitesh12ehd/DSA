#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//method 1
// void reverseQueue(queue<int>& q){
//     stack<int> st;
    
//     while(!q.empty()){
//         st.push(q.front());
//         q.pop();
//     }
//     while(!st.empty()){
//         q.push(st.top());
//         st.pop(); 
//     }
// }

//method 2
void reverseQueue(queue<int>& q){
    //base case
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);

    while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();
    }
    return 0;
}