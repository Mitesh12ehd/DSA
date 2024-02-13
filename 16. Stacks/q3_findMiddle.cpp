#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>& st,int& totalSize){
    if(st.size() == 0){
        cout << "no element in stack";
        return;
    }

    //base case
    if(st.size() == totalSize/2 + 1){
        cout << "middle element  = " << st.top();
        return;
    }

    int temp = st.top();
    st.pop();
    printMiddle(st,totalSize);
    st.push(temp);
}

int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    int totalSize = st.size();

    printMiddle(st,totalSize);

    return 0;
}