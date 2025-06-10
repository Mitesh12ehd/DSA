#include<iostream>
#include<vector>
using namespace std;

// GFG
// Shortest Common Supersequence 

/*
    ex. s1 = "brute" , s2 = "groot"
    - one supersequence is "brutegroot"
    - one supersequence is "bgruoote"
      this is smallest ans = 8

    intuition:
    - we only take common character once in our answer
    - lcs give common character between two string
    - here common characters are "rt"
    - we include rest of the char in both string in our answer
    - ans = m + n - length of lcs
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

int shortestCommonSupersequence(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    int length_of_lcs = longestCommonSubsequence(s1,s2);
    return m + n - length_of_lcs;
}

int main(){
    return 0;
}