#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//read notes

int priority(char ch){
    if(ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string& s) {
    stack<char> st;
    string ans;
    for(char ch:s){
        if((ch >= 'a' && ch <= 'z') 
            || (ch >= 'A' && ch <= 'Z')
            || (ch >= '0' && ch <= '9'))
        {
            ans.push_back(ch);
        }
        else if(ch == '('){
            st.push('(');
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            //ch is operator
            while(!st.empty() && priority(st.top()) >= priority(ch)){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    //pop remaining from stack
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

string infixToPrefix(string& s){
    reverse(s.begin(),s.end());

    //replace brackets
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    }

    string prefix = infixToPostfix(s);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main(){
    string s = "(p+q)*(m-n)";
    cout << infixToPrefix(s);
    return 0;
}