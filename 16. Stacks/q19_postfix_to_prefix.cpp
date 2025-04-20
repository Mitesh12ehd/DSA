#include<iostream>
#include<stack>
using namespace std;

//GFG
//Postfix to prefix conversion
//https://bit.ly/3UaWJxk

//read notes

string postToPre(string post_exp) {
    stack<string> st;

    for(char ch:post_exp){
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
            st.push(ch + tp2 + tp1);
        }
    }
    return st.top();
}

int main(){
    return 0;
}