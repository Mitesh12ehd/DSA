#include<iostream>
#include<vector>
using namespace std;

// Leetcode 115
// Distinct Subsequences

// see notes

// recursion
// time = O( 2 ^ (m+n))
// space = O(m+n)
int fun(int i,int j,string& s, string& t){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }

    if(s[i] == t[j]){
        return fun(i-1,j-1,s,t) + fun(i-1,j,s,t);
    }
    else{
        return fun(i-1,j,s,t);
    }
}
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    return fun(m-1,n-1,s,t);
}

// memorization
// time = O(m*n)
// space = O(m*n + m+n)
int fun(int i,int j,string& s, string& t,vector<vector<int>>& dp){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == t[j]){
        dp[i][j] = fun(i-1,j-1,s,t,dp) + fun(i-1,j,s,t,dp);
    }
    else{
        dp[i][j] = fun(i-1,j,s,t,dp);
    }
    return dp[i][j];
}
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,s,t,dp);
}

//shifting of index
int fun(int i,int j,string& s, string& t,vector<vector<int>>& dp){
    if(j == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i-1] == t[j-1]){
        dp[i][j] = fun(i-1,j-1,s,t,dp) + fun(i-1,j,s,t,dp);
    }
    else{
        dp[i][j] = fun(i-1,j,s,t,dp);
    }
    return dp[i][j];
}
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(m,n,s,t,dp);
}

// tabulation
// time = O(m*n)
// space = O(m*n)
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<double>> dp(m+1,vector<double>(n+1,0));

    //base case
    for(int i=0; i<=m; i++){
        dp[i][0] = 1;
    }
    for(int j=1; j<=n; j++){
        dp[0][j] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[m][n];
}

// space optimization 1
// time = O(m*n)
// space = O(2n)
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<double> prevRow(n+1,0);
    vector<double> currRow(n+1,0);

    //base case
    prevRow[0] = 1;
    currRow[0] = 1;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                currRow[j] = prevRow[j-1] + prevRow[j];
            }
            else{
                currRow[j] = prevRow[j];
            }
        }
        prevRow = currRow;
    }
    return (int)prevRow[n];
}

// space optimization 2
// time = O(m*n)
// space = O(n)
int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<double> currRow(n+1,0);

    //base case
    currRow[0] = 1;

    for(int i=1; i<=m; i++){
        for(int j=n; j>=0; j--){
            if(s[i-1] == t[j-1]){
                currRow[j] = currRow[j-1] + currRow[j];
            }
            else{
                currRow[j] = currRow[j];
            }
        }
    }
    return (int)currRow[n];
}

int main(){
    return 0;
}