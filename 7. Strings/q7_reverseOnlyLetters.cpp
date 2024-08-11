#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isAlphabet(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    else if(ch >= 'A' && ch <= 'Z'){
        return true;
    }
    return false;
}
string reverseOnlyLetters(string s) {
    int start = 0;
    int end = s.length()-1;

    while(start<=end){
        if(!isAlphabet(s[start])){
            start++;
        }
        else if(!isAlphabet(s[end])){
            end--;
        }
        else{
            swap(s[start],s[end]);
            start++,end--;
        }
    }

    return s;
}

int main(){
    string s="ab-cd";
    cout<<reverseOnlyLetters(s);

    return 0;
}