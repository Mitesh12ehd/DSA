#include<iostream>
#include<stack>
using namespace std;

//leetcode 2696
//minimum string length after removal substrings

int minLength(string s) {
    stack<char> st;
    for(int i=s.length()-1; i>=0; i--){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(st.top() == 'B' && s[i] == 'A'){
            st.pop();
        }
        else if(st.top() == 'D' && s[i] == 'C'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return st.size();
}

int main(){
    

    return 0;
}