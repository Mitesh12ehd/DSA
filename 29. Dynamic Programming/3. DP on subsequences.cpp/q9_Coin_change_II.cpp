#include<iostream>
#include<vector>
using namespace std;

// Leetcode 518
// Coin change II

//recusion
//time = more than O(2^n), due to picking same index again
//                         you can say exponential
//space = O(amount) because in worst case assume amount decreased by one, one ,
//                   depth of tree is size of amount in worst case
int fun(int index,int target,vector<int>& coins){
    if(index == 0){
        if(target % coins[0] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    int exclude = fun(index-1,target,coins);
    int include = 0;
    if(coins[index] <= target){
        include = fun(index,target-coins[index],coins);
    }
    return exclude + include;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    return fun(n-1,amount,coins);
}

//memorization
//time = O(n * amount)
//space = O(n*amount + amount)
int fun(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
    if(index == 0){
        if(target % coins[0] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    int exclude = fun(index-1,target,coins,dp);
    int include = 0;
    if(coins[index] <= target){
        include = fun(index,target-coins[index],coins,dp);
    }
    dp[index][target] = exclude + include;
    return dp[index][target];
}   
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return fun(n-1,amount,coins,dp);
}

//tabulation
//time = O(n * amount)
//space = O(n*amount)
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long>> dp(n,vector<long>(amount+1,-1));

    //base case
    for(int target=0; target<=amount; target++){
        if(target % coins[0] == 0){
            dp[0][target] = 1;
        }
        else{
            dp[0][target] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        for(int target=0; target<=amount; target++){
            int exclude = dp[index-1][target];
            int include = 0;
            if(coins[index] <= target){
                include = dp[index][target-coins[index]];
            }
            dp[index][target] = (long)exclude + (long)include;
        }
    }
    return dp[n-1][amount];
}

//space optimization
//time = O(n * amount)
//space = O(amount)
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<long> prevRow(amount+1,-1);

    //base case
    for(int target=0; target<=amount; target++){
        if(target % coins[0] == 0){
            prevRow[target] = 1;
        }
        else{
            prevRow[target] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        vector<long> currRow(amount+1,-1);
        for(int target=0; target<=amount; target++){
            int exclude = prevRow[target];
            int include = 0;
            if(coins[index] <= target){
                include = currRow[target-coins[index]];
            }
            currRow[target] = (long)exclude + (long)include;
        }
        prevRow = currRow;
    }
    return prevRow[amount];
}

int main(){
    return 0;
}