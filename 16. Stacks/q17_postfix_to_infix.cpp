#include<iostream>
#include<stack>
using namespace std;

//GFG
//postfix to infix conversion
// https://bit.ly/3sNZ1a2

//read notes

string postToInfix(string exp) {
    stack<string> st;

    for(char ch:exp){
        if((ch >= 'a' && ch <= 'z') 
            || (ch >= 'A' && ch <= 'Z')
            || (ch >= '0' && ch <= '9'))
        {   
            string temp = "";
            temp.push_back(ch);
            st.push(temp);
        }
        else{
            string tp1 = st.top();
            st.pop();
            string tp2 = st.top();
            st.pop();
            st.push("(" + tp2 + ch + tp1 + ")");
        }
    }
    return st.top();
}

int main(){
    return 0;
}