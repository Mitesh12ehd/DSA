#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    int maxLen = 0;
    st.push(-1);
    for(int i=0; i<s.size(); i++){
        char ch = s[i];

        if(ch == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                int len = i - st.top();
                maxLen = max(len,maxLen);
            }
            else{
                //invalid bracket-not enough opening bracket in stack for closing bracket
                st.push(i);
            }
        }
    }
    return maxLen;
}
int main(){
    string str = ")()())";
    cout << longestValidParentheses(str);
    return 0;
}