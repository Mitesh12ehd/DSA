#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Leetcode 198
// House robber
// (this problem can be asked in another way
//    maximum sum of non adjacent element)

//pattern of this question : apply dp on question that based on exclusion-inclusion
//pattern

// see notes

//recursion
//time = O(2^n)
//space = O(1)

// 1. lets try all subsequencse with given constraint
// 2. out of all subsequncse given subsequence with max sum
// we use pattern of exclusion and inclusion

int fun(int index,vector<int>& nums){
    if(index == 0){
        //we reach index = 0, only when we haven't pickup index = 1
        return nums[0];
    }
    if(index < 0){
        return 0;
    }

    int inclusionSum = nums[index] + fun(index-2,nums);
    int exclusionSum = fun(index-1,nums);
    return max(inclusionSum,exclusionSum);
}
int rob(vector<int>& nums) {
    return fun(nums.size()-1,nums);
}

//memorization

// find if recursion have overlapping subproblem
// draw recursion tree and find it out
// so here is overlapping,
// so we can apply memorization

int fun(int index,vector<int>& nums,vector<int>& dp){
    if(index == 0){
        //we reach index = 0, only when we haven't pickup index = 1
        return nums[0];
    }
    if(index < 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }

    int inclusionSum = nums[index] + fun(index-2,nums,dp);
    int exclusionSum = fun(index-1,nums,dp);
    dp[index] = max(inclusionSum,exclusionSum);
    return dp[index];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    return fun(nums.size()-1,nums,dp);
}

//tabulation
//time = O(n)
//space = O(n)

// take same size of dp array, and go to bottom to up
// write base case in intialization

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];

    for(int index=1; index<n; index++){
        int inclusionSum = nums[index];
        if(index-2 >= 0){
            inclusionSum += dp[index-2];
        }
        int exclusionSum = dp[index-1];
        dp[index] = max(inclusionSum,exclusionSum);
    }
    return dp[n-1];
}

//space optimization
//time = O(n)
//space = O(1)

// to calculate highest amount of curr index we need,
// 1. highest amount of index-1  
// 2. highest amount of index-2
// so why we storing whole dp array, we can store it in variable

int rob(vector<int>& nums) {
    int n = nums.size();
    
    //this amount is take based on we stand at index=1
    int prevIndexAmount = nums[0];
    int prev2IndexAmount = 0; 

    for(int index=1; index<n; index++){
        int inclusionSum = nums[index];
        if(index-2 >= 0){
            inclusionSum += prev2IndexAmount;
        }
        int exclusionSum = prevIndexAmount;

        int currIndexAmount = max(inclusionSum,exclusionSum);
        prev2IndexAmount = prevIndexAmount;
        prevIndexAmount = currIndexAmount;
    }
    return prevIndexAmount;
}

int main(){
    return 0;
}