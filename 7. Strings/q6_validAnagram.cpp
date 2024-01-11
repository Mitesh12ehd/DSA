#include<iostream>
#include<algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    //method 1
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());
    // if(s == t){
    //     return true;
    // }
    // return false;

    //method 2
    int frequencyTable[256] = {0};
    for(int i=0; i<s.length(); i++){
        frequencyTable[s[i]]++;
    }
    for(int i=0; i<t.length(); i++){
        frequencyTable[t[i]]--;
    }
    for(int i=0; i<256; i++){
        if(frequencyTable[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    cout<<isAnagram(s,t);

    return 0;
}