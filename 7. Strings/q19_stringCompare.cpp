#include<iostream>
using namespace std;

bool stringCompare(string s, string t){
    if(s.length() != t.length()){
        return false;
    }

    for(int i=0; i<s.length(); i++){
        if(t[i] != s[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s = "mitesh";
    string t = "migesh";
    cout << stringCompare(s,t);

    return 0;
}