#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//time = O(n) space = O(2n) = O(n)
string removeDuplicates(string s) {
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }

    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "abbaca";
    cout << removeDuplicates(s);
    return 0;
}