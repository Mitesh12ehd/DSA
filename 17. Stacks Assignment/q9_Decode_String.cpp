#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string decodeString(string s) {
    stack<string> st;
    for(auto ch:s){
        if(ch == ']'){
            string stringToRepeat = "";
            while(!st.empty() &&  st.top() != "["){
                stringToRepeat = stringToRepeat + st.top();
                st.pop();
            }
            st.pop();//it ignore opening bracket

            string numricDigit = "";
            while(!st.empty() && isdigit(st.top()[0])){ //it just conversion from stirng to int
                numricDigit = numricDigit + st.top();
                st.pop();
            }
            reverse(numricDigit.begin(),numricDigit.end());
            int n = stoi(numricDigit);

            //final decoding
            string currentDecode = "";
            while(n--){
                currentDecode = currentDecode + stringToRepeat;
            }
            st.push(currentDecode);
        }
        else{
            string temp(1,ch);
            st.push(temp);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s = "3[a2[c]]";
    cout << decodeString(s);
    return 0;
}