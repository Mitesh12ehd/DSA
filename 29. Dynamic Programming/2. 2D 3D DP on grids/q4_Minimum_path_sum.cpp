#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 64
// Minimum path sum

// Why greedy not works?
// Because in greedyness we take path that give less sum at current point
//    ,but might increase cost in future
//    ,and path we have ingnored due to our greedy nature
//    ,might give minimum sum in future

// recursion
int fun(int i,int j,vector<vector<int>>& grid){
    if(i == 0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        //return int max so that it got ignored while take minimum
        return INT_MAX;
    }

    int upper = fun(i-1,j,grid);
    int left = fun(i,j-1,grid);
    return grid[i][j] + min(upper,left);
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return fun(m-1,n-1,grid);
}

// memorization
int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i == 0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        //return int max so that it got ignored while take minimum
        return INT_MAX;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int upper = fun(i-1,j,grid,dp);
    int left = fun(i,j-1,grid,dp);
    dp[i][j] = grid[i][j] + min(upper,left);
    return dp[i][j];
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,grid,dp);
}

// tabulation
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));

    dp[0][0] = grid[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0){
                continue;
            }

            //number of ways if we go upper
            int upper = INT_MAX;
            if(i > 0){
                upper = dp[i-1][j];
            }
            int left = INT_MAX;
            if(j > 0){
                left = dp[i][j-1];
            }
            dp[i][j] = grid[i][j] + min(upper,left);
        }
    }
    return dp[m-1][n-1];
}

// space optimization
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n,INT_MAX);

    for(int i=0; i<m; i++){
        vector<int> curr(n,INT_MAX);
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0){
                curr[j] = grid[i][j];
                continue;
            }

            //number of ways if we go upper
            int upper = INT_MAX;
            if(i > 0){
                upper = prev[j];
            }
            int left = INT_MAX;
            if(j > 0){
                left = curr[j-1];
            }
            curr[j] = grid[i][j] + min(upper,left);
        }
        prev = curr;
    }
    return prev[n-1];
}

int main(){
    return 0;
}