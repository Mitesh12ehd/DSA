#include<iostream>
#include<stack>
using namespace std;

//GFG 
//Prefix to infix conversion
//https://bit.ly/3FwxK3j

//read notes

string preToInfix(string pre_exp) {
    stack<string> st;

    for(int i=pre_exp.length()-1; i>=0; i--){
        char ch = pre_exp[i];
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
            st.push("(" + tp1 + ch + tp2 + ")");
        }
    }
    return st.top();
}

int main(){
    return 0;
}