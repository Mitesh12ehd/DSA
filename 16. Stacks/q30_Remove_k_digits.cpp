#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//Leetcode 402
//Remove k digits

//read notes

string removeKdigits(string num, int k) {
    stack<char> st;
    int n = num.length();

    for(int i=0; i<n; i++){
        while(!st.empty() && k>0 && st.top() > num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(k--){
        st.pop();
    }
    if(st.empty()){
        return "0";
    }

    string result = "";
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    while(!result.empty() && result.back() == '0'){
        result.pop_back();
    }
    reverse(result.begin(),result.end());

    if(result.empty()){
        return "0";
    }
    return result;
}

int main(){
    return 0;
}