#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse_first_k_element(queue<int>& q,int k){
    if(k==0){
        return;
    }
    if(k > q.size()){
        k == q.size();
    }

    stack<int> st;
    int kTemp = k;
    int n = q.size();
    
    //step 1
    while(kTemp--){
        st.push(q.front());
        q.pop();
    }

    //step 2
    kTemp = k;
    while(kTemp--){
        q.push(st.top());
        st.pop();
    }
    //step 3
    kTemp = n-k;
    while(kTemp--){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    reverse_first_k_element(q,3);

    while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();
    }
    return 0;
}