#include<iostream>
using namespace std;

bool stringCompare(string s, string t){
    int i=0;
    for(int j=i; j<s.length(); j++){
        if(t[j] != s[i+j]){
            return false;
        }
    }
    return true;
}
int main(){
    string s = "mitesh";
    string t = "mitegh";
    cout << stringCompare(s,t);

    return 0;
}