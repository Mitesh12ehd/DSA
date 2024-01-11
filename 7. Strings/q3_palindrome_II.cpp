#include<iostream>
using namespace std;

// leetcode -- valid palindrome II

bool checkPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        else{
            start++,end--;
        }
    }
    return true;
}
bool validPalindrome(string s) {
    int i = 0; 
    int j = s.length()-1;
    while(i<=j){
        if(s[i] != s[j]){
            //this condtition skip only one charcter either starting side 
            //or ending side
            return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
int main(){
    string s="level1";
    cout << validPalindrome(s);

    return 0;
}