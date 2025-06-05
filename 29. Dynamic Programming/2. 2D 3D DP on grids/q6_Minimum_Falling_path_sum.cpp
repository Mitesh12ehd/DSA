#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 931
// Minimum falling path sum

//recursion
/*
- here starting and ending point not fixed
- can we find f(n-1,0), f(n-1,1), f(n-1,2).......f(n-1,n-1),
  and take minimum of them
- f(i,j) denote minimum sum to reach (i,j) from 0th row
- here we write recursion in reverse manner so we can move up, up-left, up-right
*/
//time = O( n * (3 ^ n))
//space = O(n)
int fun(int i,int j,vector<vector<int>>& matrix,int n){
    if(j < 0 || j>=n){
        //out of bound case, return INT_MAX so it got ignored
        return INT_MAX;
    }
    if(i == 0){
        return matrix[i][j];
    }
    
    int topRight = fun(i-1,j+1,matrix,n);
    int top = fun(i-1,j,matrix,n);
    int topLeft = fun(i-1,j-1,matrix,n);
    return matrix[i][j] + min(top,min(topRight,topLeft));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int minSum = INT_MAX;
    for(int j=0; j<n; j++){
        minSum = min(minSum,fun(n-1,j,matrix,n));
    }
    return minSum;
}

//memorization
//time = O(n^2)
//space = O(n^2 + n)
int fun(int i,int j,vector<vector<int>>& matrix,int n,vector<vector<int>>& dp){
    if(j < 0 || j>=n){
        //out of bound case, return INT_MAX so it got ignored
        return INT_MAX;
    }
    if(i == 0){
        return matrix[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int topRight = fun(i-1,j+1,matrix,n,dp);
    int top = fun(i-1,j,matrix,n,dp);
    int topLeft = fun(i-1,j-1,matrix,n,dp);
    dp[i][j] = matrix[i][j] + min(top,min(topRight,topLeft));
    return dp[i][j];
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int minSum = INT_MAX;
    for(int j=0; j<n; j++){
        minSum = min(minSum,fun(n-1,j,matrix,n,dp));
    }
    return minSum;
}

//tabulation
//time = O(n^2 + n)
//space = O(n^2)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    
    //base cases
    for(int j=0; j<n; j++){
        dp[0][j] = matrix[0][j];
    }

    //logic
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int topRight = INT_MAX;
            if(j+1 < n){
                topRight = dp[i-1][j+1];;
            }
            int top = dp[i-1][j];
            int topLeft = INT_MAX;
            if(j-1 >= 0){
                topLeft = dp[i-1][j-1];
            }
            dp[i][j] = matrix[i][j] + min(top,min(topRight,topLeft));
        }
    }
    
    int minSum = INT_MAX;
    for(int j=0; j<n; j++){
        minSum = min(minSum,dp[n-1][j]);
    }
    return minSum;
}

//space optimization
//time = O(n^2 + n)
//space = O(n)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prevRowAns(n,INT_MAX);
    
    //base cases
    for(int j=0; j<n; j++){
        prevRowAns[j] = matrix[0][j];
    }

    //logic
    for(int i=1; i<n; i++){
        vector<int> curr(n,INT_MAX);
        for(int j=0; j<n; j++){
            int topRight = INT_MAX;
            if(j+1 < n){
                topRight = prevRowAns[j+1];;
            }
            int top = prevRowAns[j];
            int topLeft = INT_MAX;
            if(j-1 >= 0){
                topLeft = prevRowAns[j-1];
            }
            curr[j] = matrix[i][j] + min(top,min(topRight,topLeft));
        }
        prevRowAns = curr;
    }
    
    int minSum = INT_MAX;
    for(int j=0; j<n; j++){
        minSum = min(minSum,prevRowAns[j]);
    }
    return minSum;
}

int main(){
    return 0;
}