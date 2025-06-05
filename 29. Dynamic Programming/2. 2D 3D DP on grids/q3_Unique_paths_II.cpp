#include<iostream>
#include<vector>
using namespace std;

// Leetcode 63
// Unique paths II

// this question is almost same as previous one.
// add condition for obstacles

//recursion
int fun(int i,int j,vector<vector<int>>& obstacleGrid){
    if(i<0 || j<0){
        return 0;
    }
    if(obstacleGrid[i][j] == 1){
        return 0;
    }
    if(i == 0 && j==0){
        return 1;
    }

    //number of ways if we go upper
    int upper = fun(i-1,j,obstacleGrid);
    //number of ways if we go left
    int left = fun(i,j-1,obstacleGrid);
    return upper + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1){
        return 0;
    }
    return fun(m-1,n-1,obstacleGrid);
}

//memorization
int fun(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
    if(i<0 || j<0){
        return 0;
    }
    if(obstacleGrid[i][j] == 1){
        return 0;
    }
    if(i == 0 && j==0){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //number of ways if we go upper
    int upper = fun(i-1,j,obstacleGrid,dp);
    //number of ways if we go left
    int left = fun(i,j-1,obstacleGrid,dp);
    dp[i][j] = upper + left;
    return dp[i][j];

}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1){
        return 0;
    }
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(m-1,n-1,obstacleGrid,dp);
}

//tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1){
        return 0;
    }

    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0){
                continue;
            }

            //number of ways if we go upper
            int upper = 0;
            if(i > 0  && obstacleGrid[i][j] != 1){
                upper = dp[i-1][j];
            }
            //number of ways if we go left
            int left = 0;
            if(j > 0 && obstacleGrid[i][j] != 1){
                left = dp[i][j-1];
            }
            dp[i][j] = upper + left; 
        }
    }
    return dp[m-1][n-1];
}

//space optimization
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1){
        return 0;
    }

    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> curr(n,0);
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0){
                curr[j] = 1;
                continue;
            }

            //number of ways if we go upper
            int upper = 0;
            if(i > 0  && obstacleGrid[i][j] != 1){
                upper = prev[j];
            }
            //number of ways if we go left
            int left = 0;
            if(j > 0 && obstacleGrid[i][j] != 1){
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