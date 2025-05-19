#include<iostream>
#include<vector>
using namespace std;

//Leetcode 509
//Fibonacci number

//see notes

//top-down doesn't mean that we go to n to 0
//bottom-up doesn't mean thqat we go to 0 to n

//recursive approach
//time = O(2^n)
//space = O(n)
int fib(int n) {
    if(n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

//memorization approach
//time = O(n)
//space = O(2n)
int helper(int n,vector<int>& dp){
    if(n <= 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = helper(n-1,dp) + helper(n-2,dp);
    return dp[n];
}
int fib(int n) {
    if(n <= 1){
        return n;
    }
    vector<int> dp(n+1,-1);
    helper(n,dp);
    return dp[n];
}

//tabulation approach
//time = O(n)
//space = O(n)
int fib(int n) {
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//space optimization
//time = O(n)
//space = O(1)
int fib(int n){
    if(n <= 1){
        return n;
    }

    int prev2 = 0;
    int prev1 = 1;
    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    return 0;
}