#include<iostream>
#include<vector>
using namespace std;

// Leetcode 1143
// Longest common subsequence

// see notes

//recursion
//time = O(2 ^ m+n)
//space = O(m+n)
int fun(int index1,int index2,string& text1,string& text2){
    if(index1 < 0 || index2 < 0){
        return 0;
    }

    if(text1[index1] == text2[index2]){
        return 1 + fun(index1 - 1,index2 - 1,text1,text2);
    } 
    return max(fun(index1 - 1,index2,text1,text2), fun(index1,index2 - 1,text1,text2)); 
}
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    return fun(m-1,n-1,text1,text2);
}

//memorization
//time = O(m*n)
//space = O((m*n) + (m+n))
int fun(int index1,int index2,string& text1,string& text2,vector<vector<int>>& dp){
    if(index1 < 0 || index2 < 0){
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    if(text1[index1] == text2[index2]){
        dp[index1][index2] = 1 + fun(index1 - 1,index2 - 1,text1,text2,dp);
    } 
    else{
        dp[index1][index2] = max(fun(index1 - 1,index2,text1,text2,dp), fun(index1,index2 - 1,text1,text2,dp));
    }
    return dp[index1][index2];
}
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    return fun(m-1,n-1,text1,text2,dp);
}

//shifting of index
int fun(int index1,int index2,string& text1,string& text2,vector<vector<int>>& dp){
    if(index1 == 0 || index2 == 0){
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    if(text1[index1 - 1] == text2[index2 - 1]){
        dp[index1][index2] = 1 + fun(index1 - 1,index2 - 1,text1,text2,dp);
    } 
    else{
        dp[index1][index2] = max(fun(index1 - 1,index2,text1,text2,dp), fun(index1,index2 - 1,text1,text2,dp));
    }
    return dp[index1][index2];
}
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    return fun(m,n,text1,text2,dp);
}

//tablulation
//time = O(m*n)
//space = O(m*n)
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    //base case
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = 0;
    }

    //logic
    for(int index1=1; index1<=m; index1++){
        for(int index2=1; index2<=n; index2++){
            if(text1[index1 - 1] == text2[index2 - 1]){
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } 
            else{
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }
    return dp[m][n];
}

//space optimization
//tablulation
//time = O(m*n)
//space = O(n)
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

int main(){
    return 0;
}