#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int>& q){
    int n = q.size();
    // 1.create 2 another queues
    queue<int> q1;
    for(int i=1; i<=n/2; i++){
        q1.push(q.front());
        q.pop();
    }
    queue<int> q2;
    for(int i=1; i<=n/2; i++){
        q2.push(q.front());
        q.pop();
    }

    //merge
    for(int i=1; i<=n/2; i++){
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
    if(n%2 != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    interleave(q);
    while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();
    }

    return 0;
}