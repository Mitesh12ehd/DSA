#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 583
// Delete Operation for Two Strings

/*
    intuition:
    - we try to find things that we don't need to delete
    - that is common subsequence between them
    - rest all the character in both string we need to delete
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

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    int length_of_lcs = longestCommonSubsequence(word1,word2);
    return (m - length_of_lcs) + (n - length_of_lcs);
}

int main(){
    return 0;
}