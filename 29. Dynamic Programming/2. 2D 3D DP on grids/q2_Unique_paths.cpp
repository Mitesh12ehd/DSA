#include<iostream>
#include<vector>
using namespace std;

// Leetcode 62
// Unique paths

// recursion
// time = O(2 ^ (m*n)) 2 call per call, and total m*n box
// space = O(max path length = (m+n))
int fun(int i,int j){
    if(i == 0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }

    //number of ways if we go upper
    int upper = fun(i-1,j);
    //number of ways if we go left
    int left = fun(i,j-1);
    return upper + left;
}
int uniquePaths(int m, int n) {    
    return fun(m-1,n-1);
}

//memorization
//time = O(m*n)
//space = O((m*n) + (m+n))
int fun(int i,int j,vector<vector<int>>& dp){
    if(i == 0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //number of ways if we go upper
    int upper = fun(i-1,j,dp);
    //number of ways if we go left
    int left = fun(i,j-1,dp);
    dp[i][j] = upper + left;
    return dp[i][j];
}
int uniquePaths(int m, int n) {    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,dp);
}

// tabulation
// time = O(m*n)
// space = O(m*n)
int uniquePaths(int m, int n) {    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0] = 1;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                continue;
            }

            //number of ways if we go upper
            int upper = 0;
            if(i > 0){
                upper = dp[i-1][j];
            }
            //number of ways if we go left
            int left = 0;
            if(j > 0){
                left = dp[i][j-1];
            }
            dp[i][j] = upper + left; 
        }
    }
    return dp[m-1][n-1];
}

// space optimization
// time = O(m*n)
// space = O(n)
int uniquePaths(int m, int n) {    
    vector<int> prev(n,0);

    for(int i=0; i<m; i++){
        vector<int> curr(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                curr[j] = 1;
                continue;
            }

            //number of ways if we go upper
            int upper = 0;
            if(i > 0){
                upper = prev[j];
            }
            //number of ways if we go left
            int left = 0;
            if(j > 0){
                left = curr[j-1];
            }
            curr[j] = upper + left; 
        }
        prev = curr;
    }
    return prev[n-1];
}

int main(){
    return 0;
}