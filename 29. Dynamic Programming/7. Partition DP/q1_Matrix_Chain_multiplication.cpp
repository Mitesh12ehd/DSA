#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// GFG
// Matrix Chain Multiplication

// see notes

// recursion
// time = O(2^n), in worst case we try all combination of matrix to multiply
// space = O(n)
int fun(int i, int j,vector<int>& arr){
    if(i == j){
        return 0;
    }

    int mini = INT_MAX;
    for(int k=i; k<j; k++){
        int operation = arr[i-1] * arr[k] * arr[j];
        mini = min(mini,operation + fun(i,k,arr) + fun(k+1,j,arr));
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    return fun(1,n-1,arr);
}

// memorization
// time = O(n^3)
// space = O(n^2 + n)
int fun(int i, int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX;
    for(int k=i; k<j; k++){
        int operation = arr[i-1] * arr[k] * arr[j];
        mini = min(mini,operation + fun(i,k,arr,dp) + fun(k+1,j,arr,dp));
    }
    dp[i][j] = mini;
    return dp[i][j];
}
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return fun(1,n-1,arr,dp);
}

// tabulation
// time = O(n^3)
// space = O(n^2)
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    //base case
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }

    //logic
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<=n-1; j++){
            int mini = INT_MAX;
            for(int k=i; k<j; k++){
                int operation = arr[i-1] * arr[k] * arr[j];
                mini = min(mini,operation + dp[i][k] + dp[k+1][j]);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int main(){
    return 0;
}