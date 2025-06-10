#include<iostream>
#include<vector>
using namespace std;

// Leetcode 44
// Wildcard matching

// recursion
// time = O(2 ^ m+n)
// space = O(m+n)

/*
    f(m-1,n-1) denote,
        is str1[0,1,.....i] matching with str2[0,1,....j]
        with gives rules?

    logic:
    1. if char at index i and j match,
        we don't need to do anything 
        return fun(i-1,j-1)

    2. if str2[j] is '?'
        then also matched
        return fun(i-1,j-1)
    
    3. if not mactched and str2[j] is not ? or *
        then return false, because string not matching

    4. if str2[j] == '*'
         we have two option
        (1) consider * as empty char
            -> decrease j
            -> i remain at same index
        (2) consider * as one char 
            -> j remain on same index, because we can consider * at any
               number of char
            -> decrease i
    
    base case:
        1. str1 and str2 both exhausted
            both string matched , return true
        2. str2 is exhauseted and str1 is not
            string not mtched return false
        3. str1 is exhausted and str 2 is not
            -here check if remaining char in str2 is all *
            -because we can replace all * with empty and we can say both
             string matched
            -if all remaing char are not *, return false
*/ 

bool fun(int i,int j,string& s,string& p){
    //base case
    if(i<0 && j<0){
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(i<0 && j>=0){
        //check remaining char in j are all the star or not
        while(j>=0){
            if(p[j] != '*'){
                return false;
            }
            j--;
        }
        return true;
    }

    //logic
    if(s[i] == p[j] || p[j] == '?'){
        return fun(i-1,j-1,s,p);
    }
    else if(p[j] != '*'){
        return false;
    }
    else{
        bool skip = fun(i,j-1,s,p);
        bool ReplaceOnechar = fun(i-1,j,s,p);
        return skip || ReplaceOnechar;
    }
}
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    return fun(m-1,n-1,s,p);
}

// memorization
// time = O(m*n)
// space = O(m*n + m+n)
bool fun(int i,int j,string& s,string& p,vector<vector<int>>& dp){
    //base case
    if(i<0 && j<0){
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(i<0 && j>=0){
        //check remaining char in j are all the star or not
        while(j>=0){
            if(p[j] != '*'){
                return false;
            }
            j--;
        }
        return true;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //logic
    if(s[i] == p[j] || p[j] == '?'){
        dp[i][j] = fun(i-1,j-1,s,p,dp);
    }
    else if(p[j] != '*'){
        dp[i][j] = false;
    }
    else{
        bool skip = fun(i,j-1,s,p,dp);
        bool ReplaceOnechar = fun(i-1,j,s,p,dp);
        dp[i][j] = skip || ReplaceOnechar;
    }
    return dp[i][j];
}
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,s,p,dp);
}

//Shifting index
bool fun(int i,int j,string& s,string& p,vector<vector<int>>& dp){
    //base case
    if(i==0 && j==0){
        return true;
    }
    if(i>=1 && j==0){
        return false;
    }
    if(i==0 && j>=1){
        //check remaining char in j are all the star or not
        while(j>=1){
            if(p[j-1] != '*'){
                return false;
            }
            j--;
        }
        return true;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //logic
    if(s[i-1] == p[j-1] || p[j-1] == '?'){
        dp[i][j] = fun(i-1,j-1,s,p,dp);
    }
    else if(p[j-1] != '*'){
        dp[i][j] = false;
    }
    else{
        bool skip = fun(i,j-1,s,p,dp);
        bool ReplaceOnechar = fun(i-1,j,s,p,dp);
        dp[i][j] = skip || ReplaceOnechar;
    }
    return dp[i][j];
}
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(m,n,s,p,dp);
}

// tabulation
// time = O(m*n)
// space = O(m*n)
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    //base case
    dp[0][0] = true;
    for(int i=1; i<=m; i++){
        dp[0][i] = false;
    }
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
        dp[0][j] = ans;
    }

    //logic
    for(int i=1; i<=m ;i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] != '*'){
                dp[i][j] = false;
            }
            else{
                bool skip = dp[i][j-1];
                bool ReplaceOnechar = dp[i-1][j];
                dp[i][j] = skip || ReplaceOnechar;
            }
        }
    }
    return dp[m][n];
}

// space optimization
// time = O(m*n)
// space = O(n)
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<int> prevRow(m+1,-1);

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
        vector<int> currRow(m+1,-1);
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