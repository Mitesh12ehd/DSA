#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkAlphabet(char ch){
    if( (ch>=97 && ch<=122) || (ch>=65 && ch<=90)){
        return true;
    }
    return false;
}
string reverseOnlyLetters(string s) {
    int i=0;
    int j=s.length() - 1;

    while(i<=j){
        if( checkAlphabet(s[i]) && checkAlphabet(s[j]) ){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if(!checkAlphabet(s[i])){
            i++;
        }
        else{
            j--;
        }
    }
    return s;
}
int main(){
    string s="ab-cd";
    cout<<reverseOnlyLetters(s);

    return 0;
}