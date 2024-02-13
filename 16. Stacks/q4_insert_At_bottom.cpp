#include<iostream>
#include<stack>
using namespace std;

void insertAtEnd(int& target,stack<int>& st){
    //base case
    if(st.empty()){
        st.push(target);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtEnd(target,st);
    st.push(temp);
}

int main(){
    stack<int> st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int target  = st.top();
    st.pop();
    insertAtEnd(target,st);

    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}