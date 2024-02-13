#include<iostream>
#include<stack>
using namespace std;

void insert_in_sorted(int& target,stack<int>& st){
    if(st.empty()){
        st.push(target);
        return;
    }
    if(st.top() >= target){
        st.push(target);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_in_sorted(target,st);
    st.push(temp);
}

void sortStack(stack<int>& st){
    if(st.empty()){
        return;
    }

    int target = st.top();
    st.pop();
    sortStack(st);
    insert_in_sorted(target,st);
}

int main(){
    stack<int> st;
    st.push(7);
    st.push(11);
    st.push(3);
    st.push(5);
    st.push(9);

    sortStack(st);
    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}