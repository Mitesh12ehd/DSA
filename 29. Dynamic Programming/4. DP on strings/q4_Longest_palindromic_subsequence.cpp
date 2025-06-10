#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 516
// Longest palindromic subsequence

/*
    ex. "b b b a b"
    ans = "bbbb" = 4

    approach:

    - in palindromic strings character are match from both side,
      and there may one char in between or may not
      ex. "b a b c b a b"

    - let's write string in reverse order
      s1 = "b b a b c b c a b"
              _ _ _ _ _   _ _
      
      s2 = "b a c b c b a b b"
            _ _   _ _ _ _ _

    - lcs of both string gives longest palindromic substring
    - how?
      - in subsequence order of char is preserved
      - so, in reverse order we try to find longest subsequence that 
        match subsequence of string 1
      - since, we find in reversed string, and if we got revered subsequnce
        same as subsequence of string 1
        (that is defination of palindrome)
*/

// Follow up : print longest common palindromic subsequence
// Ans : just use function to print lcs,

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
int longestPalindromeSubseq(string s) {
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return longestCommonSubsequence(s1,s2);
}

int main(){
    return 0;
}