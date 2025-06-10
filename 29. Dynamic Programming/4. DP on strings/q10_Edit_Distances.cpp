#include<iostream>
#include<vector>
using namespace std;

// Leetcode 72
// Edit distance

// see notes

// recursion
// time = O(3 ^ (m+n))
// space = O(m+n)
int fun(int i,int j,string& str1,string& str2){
    //base case
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }

    //logic
    if(str1[i] == str2[j]){
        return fun(i-1,j-1,str1,str2);
    }
    else{
        int insertion = 1 + fun(i,j-1,str1,str2);
        int deletion = 1 + fun(i-1,j,str1,str2);
        int replacement = 1 + fun(i-1,j-1,str1,str2);
        return min(insertion,min(deletion,replacement));
    }
}
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    return fun(m-1,n-1,word1,word2);
}

// memorization
// time = O(m*n)
// space = O(m*n + m+n)
int fun(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
    //base case
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //logic
    if(str1[i] == str2[j]){
        dp[i][j] = fun(i-1,j-1,str1,str2,dp);
    }
    else{
        int insertion = 1 + fun(i,j-1,str1,str2,dp);
        int deletion = 1 + fun(i-1,j,str1,str2,dp);
        int replacement = 1 + fun(i-1,j-1,str1,str2,dp);
        dp[i][j] = min(insertion,min(deletion,replacement));
    }
    return dp[i][j];
}
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,word1,word2,dp);
}

// Shifting of index
int fun(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
    //base case
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //logic
    if(str1[i-1] == str2[j-1]){
        dp[i][j] = fun(i-1,j-1,str1,str2,dp);
    }
    else{
        int insertion = 1 + fun(i,j-1,str1,str2,dp);
        int deletion = 1 + fun(i-1,j,str1,str2,dp);
        int replacement = 1 + fun(i-1,j-1,str1,str2,dp);
        dp[i][j] = min(insertion,min(deletion,replacement));
    }
    return dp[i][j];
}
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(m,n,word1,word2,dp);
}

// tabulation
// time = O(m*n)
// space = O(m*n)
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    //base case
    for(int j=0; j<=n; j++){
        dp[0][j] = j;
    }
    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }

    //logic
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int insertion = 1 +  dp[i][j-1];
                int deletion = 1 + dp[i-1][j];
                int replacement = 1 + dp[i-1][j-1];
                dp[i][j] = min(insertion,min(deletion,replacement));
            }
        }
    }
    return dp[m][n];
}

// space optimization
// time = O(m*n)
// space = O(2n)
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<bool> prevRow(m+1,-1);

    //base case
    prevRow[0] = true;
    for(int j=1; j<=n; j++){
        int ans = true;
        int temp = j;
        while(temp>=1){
            if(p[temp-1] != '*'){
                ans = false;
                break;
            }
            temp--;
        }
        prevRow[j] = ans;
    }

    //logic
    for(int i=1; i<=m ;i++){
        vector<bool> currRow(n+1,-1);
        currRow[0] = false;

        for(int j=1; j<=n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                currRow[j] = prevRow[j-1];
            }
            else if(p[j-1] != '*'){
                currRow[j] = false;
            }
            else{
                bool skip = currRow[j-1];
                bool ReplaceOnechar = prevRow[j];
                currRow[j] = skip || ReplaceOnechar;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n];
}

int main(){
    return 0;
}