#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        char ch = s[i];

        //opening
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }
        //closing
        else{
            if(!st.empty()){
                char topChar = st.top();

                if(ch == ')' && topChar == '('){
                    st.pop();
                }
                else if(ch == '}' && topChar == '{'){
                    st.pop();
                }
                else if(ch == ']' && topChar == '['){
                    st.pop();
                }
                else{
                    // bracket not matching
                    return false;
                }
            }
            else{
                //there is not opening bracket in stack for closing bracket
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    string str = "({[]})";
    cout << isValid(str);
    return 0;
}