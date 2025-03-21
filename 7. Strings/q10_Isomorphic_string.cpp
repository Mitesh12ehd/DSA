#include<iostream>
using namespace std;

//Leetcode 205
//Isomorphic strings

bool isIsomorphic(string s, string t) {
    int hash[256] = {0};
    bool is_T_CharMapped[256] = {0};

    for(int i=0; i<s.length(); i++){
        if( hash[s[i]] == 0  &&  is_T_CharMapped[t[i]] == 0){
            hash[s[i]] = t[i];
            is_T_CharMapped[t[i]] == true;
        }
    }
    for(int i=0; i<s.length(); i++){
        if(char(hash[s[i]]) != t[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "egg", t = "add";
    cout<<isIsomorphic(s,t);
    return 0;
}