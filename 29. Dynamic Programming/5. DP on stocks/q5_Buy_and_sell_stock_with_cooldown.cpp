#include<iostream>
#include<vector>
using namespace std;

// Leetcode 309
// Best Time to Buy and Sell Stock with Cooldown

/*
    This problem is extension of Buy and sell stock II
*/

// recursion
// time = O(2^n)
// space = O(n)
int fun(int index,bool canBuy,vector<int>& prices){
    //base case
    if(index >= prices.size()){
        //no more profit we can get now
        return 0; 
    }

    //logic
    if(canBuy){
        int BuyProfit = -(prices[index]) + fun(index+1,false,prices);
        int notBuyProfit =  fun(index+1,true,prices);
        return max(BuyProfit,notBuyProfit);
    }
    else{
        int sellProfit = prices[index] + fun(index+2,true,prices);
        int notSellProfit = fun(index+1,false,prices);
        return max(sellProfit,notSellProfit);
    }
}
int maxProfit(vector<int>& prices) {
    return fun(0,1,prices);
}

// memorization
// time = O(n)
// space = O(2n + n)
int fun(int index,int canBuy,vector<int>& prices,vector<vector<int>>& dp){
    //base case
    if(index >= prices.size()){
        //no more profit we can get now
        return 0; 
    }
    if(dp[index][canBuy] != -1){
        return dp[index][canBuy];
    }

    //logic
    if(canBuy){
        int BuyProfit = -(prices[index]) + fun(index+1,0,prices,dp);
        int notBuyProfit =  fun(index+1,1,prices,dp);
        dp[index][canBuy] = max(BuyProfit,notBuyProfit);
    }
    else{
        int sellProfit = prices[index] + fun(index+2,1,prices,dp);
        int notSellProfit = fun(index+1,0,prices,dp);
        dp[index][canBuy] = max(sellProfit,notSellProfit);
    } 
    return dp[index][canBuy];  
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return fun(0,1,prices,dp);
}

// tabulation
// time = O(n)
// space = O(2n)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //here we are dealing with index+2, so size =n+2
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    //in base case we mark dp[n][0] and dp[n][1] to 0 so intilize dp array with 0,
    //so don't need to write base case

    //logic
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<=1; canBuy++){
            if(canBuy){
                int BuyProfit = -(prices[index]) + dp[index+1][0];
                int notBuyProfit = dp[index+1][1];
                dp[index][canBuy] = max(BuyProfit,notBuyProfit);
            }
            else{
                int sellProfit = prices[index] + dp[index+2][1];
                int notSellProfit = dp[index+1][0];
                dp[index][canBuy] = max(sellProfit,notSellProfit);
            } 
        }
    }
    return dp[0][1];
}

// space optimization
/*
    here we are dealing with index+1 and index+2, so we need to carry 
    2 next rows and 1 currrows
*/
// time = O(n)
// space = O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> next1Row(2,0);
    vector<int> next2Row(2,0);
    vector<int> currRow(2,0);

    //logic
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<=1; canBuy++){
            if(canBuy){
                int BuyProfit = -(prices[index]) + next1Row[0];
                int notBuyProfit = next1Row[1];
                currRow[canBuy] = max(BuyProfit,notBuyProfit);
            }
            else{
                int sellProfit = prices[index] + next2Row[1];
                int notSellProfit = next1Row[0];
                currRow[canBuy] = max(sellProfit,notSellProfit);
            } 
        }
        next2Row = next1Row;
        next1Row = currRow;
    }
    return next1Row[1];
}

int main(){
    return 0;
}