#include<iostream>
#include<vector>
using namespace std;

// Leetcode 122
// Best Time to Buy and Sell Stock II

/*
 -there are lot of combinations to buy and sell stocks on different days
 -so we can apply recursion
*/

// recursion
// time = O(2^n)
// space = O(n)
/*
    - at any index, we must have idea about that we have bought stock previously
      or not
    - so we need to carry one flag that indicate we can buy stock on curr
      index or not
    - and also we need to start from index 0 because we need info about 
      stock is bough previously or not

    fun(0,true) - true is flag indicate we can buy stocks on index 0
    denote what maxProfit we can earn till index 0

    logic:
    1. if canBuy = true
       we have two option
       (1) we buy stock
            profit = -(price[index]) + f(index+1,false)
            
            here we take -(price[index]) because if we sell stock on future,
                 we get profit = future price -(price[index])
       (2) we not buy stock
            profit = fun(index+1,true)

    1. if canBuy = false
       we have two option
       (1) we sell stock
            profit = price[index] + f(index+1,true)
       (2) we not sell stock
            profit = fun(index+1,false)

    base case:
        hit only when index=n
        and we don't get any max profit more than 0
        return 0
*/
int fun(int index,bool canBuy,vector<int>& prices){
    //base case
    if(index == prices.size()){
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
        int sellProfit = prices[index] + fun(index+1,true,prices);
        int notSellProfit = fun(index+1,false,prices);
        return max(sellProfit,notSellProfit);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return fun(0,true,prices);
}

// memorization
/*
    two changing variable
    1. index: 0 to n-1
    2. canBuy : 0 or 1
    we need n*2 size dp array
*/
// time = O(n)
// space = O(2n + n)
int fun(int index,int canBuy,vector<int>& prices,vector<vector<int>>& dp){
    //base case
    if(index == prices.size()){
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
        int sellProfit = prices[index] + fun(index+1,1,prices,dp);
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
/*
    note: here base case hit when index=n
          so we need to store ans for index=n
          we require n+1 * 2 size dp array in tabulation
*/
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));

    //base case
    dp[n][0] = 0;
    dp[n][1] = 0;

    //logic
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<=1; canBuy++){
            if(canBuy){
                int BuyProfit = -(prices[index]) + dp[index+1][0];
                int notBuyProfit = dp[index+1][1];
                dp[index][canBuy] = max(BuyProfit,notBuyProfit);
            }
            else{
                int sellProfit = prices[index] + dp[index+1][1];
                int notSellProfit = dp[index+1][0];
                dp[index][canBuy] = max(sellProfit,notSellProfit);
            } 
        }
    }
    return dp[0][1];
}

// space optimization
// time = O(n)
// space = O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> nextRow(2,-1);

    //base case
    nextRow[0] = 0;
    nextRow[1] = 0;

    //logic
    for(int index=n-1; index>=0; index--){
        vector<int> currRow(2,-1);
        for(int canBuy=0; canBuy<=1; canBuy++){
            if(canBuy){
                int BuyProfit = -(prices[index]) + nextRow[0];
                int notBuyProfit = nextRow[1];
                currRow[canBuy] = max(BuyProfit,notBuyProfit);
            }
            else{
                int sellProfit = prices[index] + nextRow[1];
                int notSellProfit = nextRow[0];
                currRow[canBuy] = max(sellProfit,notSellProfit);
            } 
        }
        nextRow = currRow;
    }
    return nextRow[1];
}

int main(){
    return 0;
}