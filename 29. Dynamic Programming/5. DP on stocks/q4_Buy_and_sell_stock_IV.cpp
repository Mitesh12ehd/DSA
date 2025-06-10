#include<iostream>
#include<vector>
using namespace std;

// Leetcode 188
// Best Time to Buy and Sell Stock IV

/*
    This problem is extension of previous problem,
    in previous problem, we can do 2 transaction
    but here we can do k transaction
*/

// space optimization
// time = O(n*2*k)
// space = O(2*k)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> nextDP(2,vector<int>(k+1,-1));

    //base case
    //when index==n
    for(int canBuy=0; canBuy<=1; canBuy++){
        for(int count=0; count<=k; count++){
            nextDP[canBuy][count] = 0;
        }
    }

    //logic
    for(int index=n-1; index>=0; index--){
        vector<vector<int>> currDP(2,vector<int>(k+1,-1));

        for(int canBuy=0; canBuy<=1; canBuy++){
            //base case
            currDP[canBuy][0] = 0;

            for(int count=1; count<=k; count++){
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
    return nextDP[1][k];
}

int main(){
    return 0;
}