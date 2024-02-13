#include<iostream>
#include<stack>
using namespace std;

//time = O(n) space=O(n)
int countRev (string s){
    if(s.size() % 2 == 1){
        return -1;
    }

    stack<char> st;
    int count = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty()  &&  st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if(a == b){
            count = count + 1;
        }
        else{
            count = count + 2;
        }
    }
    return count;
}
int main(){
    string s = "}{{}}{{{";
    cout << countRev(s);
    return 0;
}