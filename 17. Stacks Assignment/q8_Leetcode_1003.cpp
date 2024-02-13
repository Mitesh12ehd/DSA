#include<iostream>
#include<stack>
using namespace std;

//method 1 time = O(n^2)
// bool isValid(string s) {
//     if(s.size() == 0){
//         return true;
//     }

//     int findIndex = s.find("abc");
//     if(findIndex != string::npos){
//         //found
//         string tLeft = s.substr(0,findIndex);
//         string tRight = s.substr(findIndex+3 , s.size()-1);
//         return isValid(tLeft + tRight);
//     }
//     return false;
// }
  
//method 2 Time = O(n) space = O(n)
bool isValid(string s) {
    stack<char> st;
    for(char ch:s){
        if(ch == 'a'){
            st.push(ch);
        }
        else if(ch == 'b'){
            if(!st.empty() && st.top() == 'a'){
                st.push(ch);
            }
            else{
                return false;
            }
        }
        else if(ch == 'c'){
            if(!st.empty() && st.top() == 'b'){
                st.pop();
                if(!st.empty() && st.top() == 'a'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s = "abcabcababcc";
    cout << isValid(s);

    return 0;
}