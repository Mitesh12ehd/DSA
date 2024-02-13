#include<iostream>
#include<stack>
using namespace std;

void insert_in_sorted(int& target,stack<int>& st){
    if(st.top() >= target){
        st.push(target);
        return;
    }
    if(st.empty()){
        st.push(target);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_in_sorted(target,st);
    st.push(temp);
}

int main(){
    int target = 5;
    stack<int> st;
    st.push(8);
    st.push(6);
    st.push(4);
    st.push(2);

    insert_in_sorted(target,st);

    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}