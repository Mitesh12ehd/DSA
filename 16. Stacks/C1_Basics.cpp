#include<iostream>
#include<stack>
using namespace std;



int main(){
    //creation
    // stack<int> st;

    // //insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // //removal
    // st.pop();

    // //check element on top
    // cout << "\n element on top = " << st.top() << endl;

    // //size
    // cout << "\n size = " << st.size() << endl;

    // //check empty or not
    // cout << "\n stack is empty? = " << st.empty() << endl;

    //print stack
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}