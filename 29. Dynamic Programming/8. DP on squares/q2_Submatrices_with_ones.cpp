#include<iostream>
#include<vector>
using namespace std;

// Leetcode 1277
// Count Square Submatrices with All Ones

// see notes

// tabulation
// time = O(m*n)
// space = O(m*n)
int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,0));

    //mark first row and first column
    for(int i=0; i<m; i++){
        dp[i][0] = matrix[i][0];
    }
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }

    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            count += dp[i][j];
        }
    }
    return count;
}

int main(){
    return 0;
}