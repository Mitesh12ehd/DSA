#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkVowels(char ch){
    if( ch==97 || ch==101 || ch==105 || ch==111 || ch==117 ||
        ch==65 || ch==69  || ch==73  || ch==79  || ch==85 ){
        return true;
    }
    return false;
}
string reverseOnlyVowels(string s) {
    int i=0;
    int j=s.length() - 1;

    while(i<=j){
        if( checkVowels(s[i]) && checkVowels(s[j]) ){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if(!checkVowels(s[i])){
            i++;
        }
        else{
            j--;
        }
    }
    return s;
}
int main(){
    string s="leetcode";
    cout<<reverseOnlyVowels(s);

    return 0;
}