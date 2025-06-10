#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 1312
// Minimum Insertion Steps to Make a String Palindrome

/*
    - one way to make string palindrome is 
        mitesh + shetim
    - so one thing is sure that we make any string palindrome within
      n = str.length() insertion
    
    - but we need to find minimum number of insertion

    - ex. "a b c a a"
      ans = "a a b c b a a"   = 2 insertions
               _     _

    - intiution
      if we find length longest palindromic subsequence = x,
      then we need to add n-x character to make string palindrome
      and that is minimum insertion

      we have exclude that part that we don't need to insert
*/

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<int> prevRow(n+1,0);

    //base case
    for(int j=0; j<=n; j++){
        prevRow[j] = 0;
    }

    //logic
    for(int index1=1; index1<=m; index1++){
        vector<int> currRow(n+1,0);
        for(int index2=1; index2<=n; index2++){
            if(text1[index1 - 1] == text2[index2 - 1]){
                currRow[index2] = 1 + prevRow[index2 - 1];
            } 
            else{
                currRow[index2] = max(prevRow[index2],currRow[index2 - 1]);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n];
}
int minInsertions(string s) {
    int n = s.length();
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    int length_of_longest_palindromic_subsequence =  longestCommonSubsequence(s1,s2);

    return n - length_of_longest_palindromic_subsequence;
}

int main(){
    return 0;
}