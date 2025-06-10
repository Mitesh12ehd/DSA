#include<iostream>
#include<vector>
using namespace std;

// Leetcode 714
// Best Time to Buy and Sell Stock with transaction fee

/*
    This problem is extension of buy and sell stock II
    here when we sell stock, we pay transaction fee by deduct it
*/

int maxProfit(vector<int>& prices, int fee) {
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
                int sellProfit = prices[index] + nextRow[1] - fee;
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