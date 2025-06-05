#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 120
// Triangle

//recursion
/*
  in some of the previous problem , we go f(m-1,n-1) to f(0,0),
  but here no fixed ending point,
  but starting point is fixed, 
  so we can start from f(0,0) , it denote min path sum from (0,0) to last row,
  
  f(i,j) tells number of unique ways to reach (i,j) from (0,0)
*/
//time = O(2^n)
//space = O(n)
int fun(int i,int j,vector<vector<int>>& triangle,int n){
    if(i == n-1){
        return triangle[i][j];
    }

    int bottom = fun(i+1,j,triangle,n);
    int nextBottom = fun(i+1,j+1,triangle,n);
    return triangle[i][j] + min(bottom,nextBottom);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return fun(0,0,triangle,n);
}

//memorization
/*
- find overlapping subproblem by drawing recursion tree,
- we found overlapping subproblem
- what is the size of dp array ? 
    -> i and j are changing variable
    -> range of i = 0 to m-1
    -> range of j = 0 to n-1
*/
//time = O(n^2)
//space = O(n^2 + n)
int fun(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    if(i == n-1){
        return triangle[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int bottom = fun(i+1,j,triangle,n,dp);
    int nextBottom = fun(i+1,j+1,triangle,n,dp);
    dp[i][j] = triangle[i][j] + min(bottom,nextBottom);
    return dp[i][j];
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return fun(0,0,triangle,n,dp);
}

//tabulation
/*
- Recusion is always top down because we go down down from top,
  and tabulation is always bottom-up
- Whatever direction we follow in recursion , 
  we always follow reverse direction in tabulation method

 1. write base case :
        -> here base case can be trigger n time
        -> trigger for last row
 2. here we go from n-2 to 0 th row
    and value of j can be at max i, ex. for 2nd row j=0,1,2
    ex. 1
        2 3
        4 5 6
        7 8 9 10
    (we can go from j=0,1....i, it doesn't affect the answer)
*/
//time = O(n^2)
//space = O(n^2)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    //base cases
    for(int j=0; j<n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int bottom = dp[i+1][j];
            int nextBottom = dp[i+1][j+1];
            dp[i][j] = triangle[i][j] + min(bottom,nextBottom);
        } 
    }
    return dp[0][0];
}

//space optimization
/*
- use same concept as some of the previous question
*/
//time = O(n^2)
//space = O(n)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> ansOfNextRow(n,INT_MAX);

    //base cases
    for(int j=0; j<n; j++){
        ansOfNextRow[j] = triangle[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        vector<int> curr(n,INT_MAX);
        for(int j=i; j>=0; j--){
            int bottom = ansOfNextRow[j];
            int nextBottom = ansOfNextRow[j+1];
            curr[j] = triangle[i][j] + min(bottom,nextBottom);
        } 
        ansOfNextRow = curr;
    }
    return ansOfNextRow[0];
}

int main(){
    return 0;
}