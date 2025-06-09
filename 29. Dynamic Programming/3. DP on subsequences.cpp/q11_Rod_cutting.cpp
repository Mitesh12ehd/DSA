#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// GFG
// Rod cutting

// see notes

//recursion
/* 
    fun(index,N)
    - denote, till index, what is max cost we can get to form N
                                                         (make peice that sum N)
    - here we can cut again same length(like unbounded knapsack)

    - base case
        when index == 0
        rodlength is always 1,
        whatever N we want to form ,
            max price we can get is price[0] * N(1) 
                                                1 is rod length
*/
//time = more than O(2^n), we can say exponential
//space = O(n)
int fun(int index,int N,vector<int>& price){
    if(index == 0){
        return price[0] * N;
    }

    int exclude = fun(index-1,N,price);
    int include = INT_MIN;
    int rodLength = index+1;
    if(rodLength <= N){
        include = price[index] + fun(index,N-rodLength,price);
    }
    return max(include,exclude);
}
int cutRod(vector<int> &price) {
    int n = price.size();
    return fun(n-1,n,price);
}

//memorization
//time = O(n^2)
//space = O(n^2 + n)
int fun(int index,int N,vector<int>& price,vector<vector<int>>& dp){
    if(index == 0){
        return price[0] * N;
    }
    if(dp[index][N] != -1){
        return dp[index][N];
    }

    int exclude = fun(index-1,N,price,dp);
    int include = INT_MIN;
    int rodLength = index+1;
    if(rodLength <= N){
        include = price[index] + fun(index,N-rodLength,price,dp);
    }
    dp[index][N] = max(include,exclude);
    return dp[index][N];
}
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return fun(n-1,n,price,dp);
}

//tabulation
//time = O(n^2)
//space = O(n^2)
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
    //base case
    for(int N=0; N<=n; N++){
        dp[0][N] = price[0] * N;
    }

    //logic
    for(int index=1; index<n; index++){
        for(int N=0; N<=n; N++){
            int exclude = dp[index-1][N];
            int include = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                include = price[index] + dp[index][N-rodLength];
            }
            dp[index][N] = max(include,exclude);
        }
    }
    return dp[n-1][n];
}

//space optimization
//time = O(n^2)
//space = O(2n)
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> prevRow(n+1,-1);
    
    //base case
    for(int N=0; N<=n; N++){
        prevRow[N] = price[0] * N;
    }

    //logic
    for(int index=1; index<n; index++){
        vector<int> currRow(n+1,-1);
        for(int N=0; N<=n; N++){
            int exclude = prevRow[N];
            int include = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                include = price[index] + currRow[N-rodLength];
            }
            currRow[N] = max(include,exclude);
        }
        prevRow = currRow;
    }
    return prevRow[n];
}

//space optimization 2
//time = O(n^2)
//space = O(n)
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> prevRow(n+1,-1);
    
    //base case
    for(int N=0; N<=n; N++){
        prevRow[N] = price[0] * N;
    }

    //logic
    for(int index=1; index<n; index++){
        for(int N=0; N<=n; N++){
            int exclude = prevRow[N];
            int include = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                include = price[index] + prevRow[N-rodLength];
            }
            prevRow[N] = max(include,exclude);
        }
    }
    return prevRow[n];
}

int main(){
    return 0;
}