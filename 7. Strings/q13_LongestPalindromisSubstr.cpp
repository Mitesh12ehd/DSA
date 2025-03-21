#include<iostream>
#include<string>
using namespace std;

//Leetcode 5
//Longest palindromic substring 

//brute force time = O(n^3) space = O(1)
bool checkPalindrome(string &s,int start ,int end){
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
string longestPalindrome(string s) {
    string ans="";

    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            if(checkPalindrome(s,i,j)){
                string t = s.substr( i , j-i+1);
                ans = (t.length() > ans.length())  ?  (t)  :  (ans);
            }
        }
    }
    return ans;
}

//better approach
/*
Expand Around Center:

Each palindrome has a center. It can be a single character (odd-length palindromes) or a pair of adjacent characters (even-length palindromes).
For each character in the string, expand outward to check the longest palindrome centered at that index.
Track the longest palindrome found.
Steps:

Iterate through each index i in the string.
Expand in both possible ways:
Odd length palindrome (i as the middle of the palindrome).
Even length palindrome (i and i+1 as the middle).
Keep track of the longest palindrome found and return it.
*/
string longestPalindrome(string s) {
    int n = s.length();
    int maxLength = 0;
    string ans = "";

    for(int i=0; i<n; i++){
        int p1=i, p2=i;
        while((p1>=0 && p2<n) && s[p1] == s[p2]){
            p1--;
            p2++;
        }
        if((p2-p1-1) > maxLength){
            maxLength = p2-p1-1;
            ans = s.substr(p1+1,maxLength);
        }

        p1=i, p2=i+1;
        while((p1>=0 && p2<n) && s[p1] == s[p2]){
            p1--;
            p2++;
        }
        if((p2-p1-1) > maxLength){
            maxLength = p2-p1-1;
            ans = s.substr(p1+1,maxLength);
        }
    }

    return ans;
}

//most optimized solution can be done using dynamic programming

int main(){
    string s = "babad";
    cout << longestPalindrome(s);

    return 0;
}