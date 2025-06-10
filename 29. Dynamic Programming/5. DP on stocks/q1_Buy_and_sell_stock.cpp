#include<iostream>
#include<vector>
using namespace std;

// Leetcode 121
// Best Time to Buy and Sell Stock

/*
    ex . [7,1,5,3,6,4]
    -if we sell stock on day 5, we try to buy on day 0 -> 4,
    -we choose day where prices is minimum

    -ofcourse we buy stock day that have minimum price, and
     sell on day who have maximum prices after buying day
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int miniPrice = prices[0];
    int maxProfit = 0; //we sell on 0th day itselt and make profit 0
    for(int i=1; i<n; i++){
        int todayProfit = prices[i] - miniPrice;
        maxProfit = max(maxProfit,todayProfit);
        
        //check if we can buy stock today
        miniPrice = min(miniPrice,prices[i]);
    }
    return maxProfit;
}

int main(){
    return 0;
}