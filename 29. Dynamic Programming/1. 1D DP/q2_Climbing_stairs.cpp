#include<iostream>
#include<vector>
using namespace std;

//Leetcode 70
//Climbing stairs

//How to identify dp problem?
// 1. count total number of ways
// 2. find out minimum maximum way to reach/achieve
// 4. find out best way to find out something

//ex. here n=3
// we can jump  0 -> 1 -> -> 2 -> 3
//              0 --> 2 -> 3
//              0 -> 1 --> 3
//              there are total 3 ways

//How to write recurrence relation?
// 1. try to represent problem in terms of index
// 2. do all possible stuff on that index
// 3. if que says all ways sum up all stuffs
// 4. if que says find minimum, take minimum of all stuffs 
// 5. if que says find maximum, take maximum of all stuffs

// for this problem
//     0 ....................... n
//     f(n) = number of ways to reach n
// f(n){
//     if (index == 0){
//         return 1
//     } 

//     return f(n-1) + f(n-2)
// }

// what is index = 1
// then we go into nagative while f(n-2) = f(-1)
// so write one more base case for index = 1

// optimize same way in fibonacii
// draw tree to understand


//recursion
int climbStairs(int n) {
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }

    return climbStairs(n-1) + climbStairs(n-2);
}

//memorization
int helper(int n,vector<int>& dp){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}
int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}

//tabulation
int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//space optimization
int climbStairs(int n){
    int prev1 = 1;
    int prev2 = 1;

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