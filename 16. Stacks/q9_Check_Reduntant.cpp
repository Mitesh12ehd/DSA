#include<iostream>
#include<stack>
using namespace std;

bool isOpenParenthesis(char ch){
    if(ch=='(' || ch=='{' || ch=='[')
        return true;
    return false;
}
bool checkReduntant(string &s){
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        char ch = s[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            if(st.top() == '('){
                return true;
            }
            else{
                while(st.top()  !=  '('){
                    st.pop();
                }
                st.pop();
            }
        }
        //ignore the char like a,b,c
    }
    return false;
}
int main(){
    string str = "(a+(b))";
    cout << checkReduntant(str);

    return 0;
}