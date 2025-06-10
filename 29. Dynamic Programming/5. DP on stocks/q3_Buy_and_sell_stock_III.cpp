#include<iostream>
#include<vector>
using namespace std;

// Leetcode 123
// Best Time to Buy and Sell Stock III

/*
    -here we can do 2 transaction
    -can buy and sell two stocks overall
    -we can't hold two stocks together
    -this problem is extension of buy and sell stock II,
     where we try to find max profit by selling infinte(not limited) stock
*/

// recursion
// time = O(2^n)
// space = O(n)
/*
    here we need one more varible that keep track of remaing transaction
*/
int fun(int index,bool canBuy,int count,vector<int>& prices){
    //base case
    if(index == prices.size()){
        //no more profit we can get now
        return 0; 
    }
    if(count == 0){
        return 0;
    }

    //logic
    if(canBuy){
        int BuyProfit = -(prices[index]) + fun(index+1,false,count,prices);
        int notBuyProfit =  fun(index+1,true,count,prices);
        return max(BuyProfit,notBuyProfit);
    }
    else{
        int sellProfit = prices[index] + fun(index+1,true,count-1,prices);
        int notSellProfit = fun(index+1,false,count,prices);
        return max(sellProfit,notSellProfit);
    }
}
int maxProfit(vector<int>& prices) {
    return fun(0,true,2,prices);
}

// memorization
/*
    Changing variable: 
        index: 0 to n-1,  canBuy:0,1   count:0,1,2
*/
// time = O(n*2*3)
// space = O(n*2*3 + n)
int fun(int index,bool canBuy,int count,vector<int>& prices,vector<vector<vector<int>>>& dp){
    //base case
    if(index == prices.size()){
        //no more profit we can get now
        return 0; 
    }
    if(count == 0){
        return 0;
    }
    if(dp[index][canBuy][count] != -1){
        return dp[index][canBuy][count];
    }

    //logic
    if(canBuy){
        int BuyProfit = -(prices[index]) + fun(index+1,false,count,prices,dp);
        int notBuyProfit =  fun(index+1,true,count,prices,dp);
        dp[index][canBuy][count] = max(BuyProfit,notBuyProfit);
    }
    else{
        int sellProfit = prices[index] + fun(index+1,true,count-1,prices,dp);
        int notSellProfit = fun(index+1,false,count,prices,dp);
        dp[index][canBuy][count] = max(sellProfit,notSellProfit);
    }
    return dp[index][canBuy][count];
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();  
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return fun(0,true,2,prices,dp);
}

// tabulation
// time = O(n*2*3)
// space = O(n*2*3)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

    //base case
    //when index==n
    for(int canBuy=0; canBuy<=1; canBuy++){
        for(int count=0; count<=2; count++){
            dp[n][canBuy][count] = 0;
        }
    }
    //when count==0
    for(int index=0; index<=n; index++){
        for(int canBuy=0; canBuy<=1; canBuy++){
            dp[index][canBuy][0] = 0;
        }
    }

    //logic
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<=1; canBuy++){
            for(int count=1; count<=2; count++){
                //logic
                if(canBuy){
                    int BuyProfit = -(prices[index]) + dp[index+1][0][count];
                    int notBuyProfit = dp[index+1][1][count];
                    dp[index][canBuy][count] = max(BuyProfit,notBuyProfit);
                }
                else{
                    int sellProfit = prices[index] + dp[index+1][1][count-1];
                    int notSellProfit = dp[index+1][0][count];
                    dp[index][canBuy][count] = max(sellProfit,notSellProfit);
                }
            }
        }
    }
    return dp[0][1][2];
}

// space optimization
// time = O(n*2*3)
// space = O(2*3)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> nextDP(2,vector<int>(3,-1));

    //base case
    //when index==n
    for(int canBuy=0; canBuy<=1; canBuy++){
        for(int count=0; count<=2; count++){
            nextDP[canBuy][count] = 0;
        }
    }

    //logic
    for(int index=n-1; index>=0; index--){
        vector<vector<int>> currDP(2,vector<int>(3,-1));

        for(int canBuy=0; canBuy<=1; canBuy++){
            //base case
            currDP[canBuy][0] = 0;

            for(int count=1; count<=2; count++){
                //logic
                if(canBuy){
                    int BuyProfit = -(prices[index]) + nextDP[0][count];
                    int notBuyProfit = nextDP[1][count];
                    currDP[canBuy][count] = max(BuyProfit,notBuyProfit);
                }
                else{
                    int sellProfit = prices[index] + nextDP[1][count-1];
                    int notSellProfit = nextDP[0][count];
                    currDP[canBuy][count] = max(sellProfit,notSellProfit);
                }
            }
        }
        nextDP = currDP;
    }
    return nextDP[1][2];
}

int main(){
    return 0;
}