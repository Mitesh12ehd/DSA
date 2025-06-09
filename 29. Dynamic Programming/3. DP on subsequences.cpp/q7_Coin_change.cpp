#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 322
// Coin change

/*
 Why greedy not works here?
 - ex. [9,6,5,1] target=11
 - if we pick greedly we pick (9,1,1) totalcoin = 3
 - but optimal pick will be (6,5) totalcoin = 2
*/

//recursion
/*
 fun(n-1,target) denote minimum coin required from 0 to n-1 index to fullfill
 given target

 - here we have infinite supply so if we include current coin, 
   we can include it again, so call for fun(index) while including
*/
//time = O(more than 2^n) because we consider included index also,
//                        we can tell expontial
//space = O(amount) because in worst case assume amount decreased by one, one ,
//                   depth of tree is size of amount in worst case
int fun(int index,int target,vector<int>& coins){
    if(index == 0){
        if(target % coins[0] == 0){
            return target/coins[index];
        }
        else{
            return INT_MAX;
        }
    }

    int exclude = fun(index-1,target,coins);
    int include = INT_MAX;
    if(coins[index] <= target){
        int temp = fun(index,target-coins[index],coins);;
        if(temp != INT_MAX){
            include = 1 + temp;
        }
    }
    return min(exclude,include);
}
int coinChange(vector<int>& coins, int amount) {
    int ans = fun(coins.size()-1,amount,coins);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

//memorization
//time = O(n * amount)
//space = O(n*amount + amount)
int fun(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
    if(index == 0){
        if(target % coins[0] == 0){
            return target/coins[0];
        }
        else{
            return INT_MAX;
        }
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    int exclude = fun(index-1,target,coins,dp);
    int include = INT_MAX;
    if(coins[index] <= target){
        int temp = fun(index,target-coins[index],coins,dp);;
        if(temp != INT_MAX){
            include = 1 + temp;
        }
    }
    dp[index][target] = min(exclude,include);
    return dp[index][target];
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    int ans = fun(coins.size()-1,amount,coins,dp);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

//tabulation
//time = O(n * amount)
//space = O(n*amount)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    
    //base case
    for(int target=0; target<=amount; target++){
        if(target % coins[0] == 0){
            dp[0][target] = target/coins[0];
        }
        else{
            dp[0][target] = INT_MAX;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        for(int target=0; target<=amount; target++){
            int exclude = dp[index-1][target];;
            int include = INT_MAX;
            if(coins[index] <= target){
                int temp = dp[index][target-coins[index]];
                if(temp != INT_MAX){
                    include = 1 + temp;
                }
            }
            dp[index][target] = min(exclude,include);
        }
    }
    if(dp[n-1][amount] == INT_MAX){
        return -1;
    }
    return dp[n-1][amount];
}

//space optimization
/*
 - use currRow where dp[index]
 - use prevRow where dp[index-1]
*/
//time = O(n * amount)
//space = O(amount)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prevRow(amount+1,-1);
    
    //base case
    for(int target=0; target<=amount; target++){
        if(target % coins[0] == 0){
            prevRow[target] = target/coins[0];
        }
        else{
            prevRow[target] = INT_MAX;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        vector<int> currRow(amount+1,-1);
        for(int target=0; target<=amount; target++){
            int exclude = prevRow[target];
            int include = INT_MAX;
            if(coins[index] <= target){
                int temp = currRow[target-coins[index]];
                if(temp != INT_MAX){
                    include = 1 + temp;
                }
            }
            currRow[target] = min(exclude,include);
        }
        prevRow = currRow;
    }
    if(prevRow[amount] == INT_MAX){
        return -1;
    }
    return prevRow[amount];
}

int main(){
    return 0;
}