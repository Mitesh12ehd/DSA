#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 312
// Burst baloons

// recursion
// time = O(2^m)
// space = O(m)
int fun(int i,int j,vector<int>& nums){
    if(i>j){
        return 0;
    }

    int maxCoin = 0;
    for(int k=i; k<=j; k++){
        //why we are taking nums[i-1] and nums[j+1] not nums[k-1] and nums[k+1]
        //because recusion go top to bottom
        //kth baloon is last baloon to burst in [i,j] range
        //rest baloon are already burst by subproblems
        //(here we can burst baloon in any order)
        int coins = nums[i-1] * nums[k] * nums[j+1];
        maxCoin = max(maxCoin,coins + fun(i,k-1,nums) + fun(k+1,j,nums));
    }
    return maxCoin;
}
int maxCoins(vector<int>& nums) {
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    
    int m = nums.size();
    return fun(1,m-2,nums);
}

// memorization
// time = O(m^3)
// space = O(m^2 + m)
int fun(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int maxCoin = 0;
    for(int k=i; k<=j; k++){
        int coins = nums[i-1] * nums[k] * nums[j+1];
        maxCoin = max(maxCoin,coins + fun(i,k-1,nums,dp) + fun(k+1,j,nums,dp));
    }
    dp[i][j] = maxCoin;
    return dp[i][j];
}
int maxCoins(vector<int>& nums) {
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    
    int m = nums.size();
    vector<vector<int>> dp(m,vector<int>(m,-1));
    return fun(1,m-2,nums,dp);
}

// tabulation
// time = O(m^3)
// space = O(m^2 + m)
int maxCoins(vector<int>& nums) {
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    
    int m = nums.size();
    vector<vector<int>> dp(m,vector<int>(m,-1));

    // base case : we intilize dp to 0 so no need to write base case

    for(int i=m-2; i>=1; i++){
        for(int j=1; j<=m-2; j++){
            int maxCoin = 0;
            for(int k=i; k  <=j; k++){  
                //handled base case
                if(i > j){
                    continue;
                }

                int coins = nums[i-1] * nums[k] * nums[j+1];
                maxCoin = max(maxCoin,coins + dp[i][k-1] + dp[k+1][j]);
            }
            dp[i][j] = maxCoin;
        }
    }
    return dp[1][m-2];
}

int main(){
    return 0;
}