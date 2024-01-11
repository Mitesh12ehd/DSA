#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


// time O(n) , space O(n)
void findMaxProfit(vector<int>& prices,int& min_price,int& max_profit,int i){
    //base case
    if(i == prices.size()){
        return;
    }

    //solve one case
    if(prices[i] < min_price){
        min_price = prices[i];
    }
    int  today_sell_profit = prices[i] - min_price;
    if(today_sell_profit > max_profit){
        max_profit = today_sell_profit;
    }

    //recursive call
    findMaxProfit(prices,min_price,max_profit,i+1);
}

//recursive
int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    int i = 0;

    findMaxProfit(prices, min_price, max_profit, i);
    return max_profit;
}

//iterative
// int maxProfit(vector<int>& prices) {
//     int min_price = INT_MAX;
//     int max_profit = INT_MIN;

//     for(int i=0; i<prices.size(); i++){
//         if(prices[i] < min_price){
//             min_price = prices[i];
//         }
//         int  today_sell_profit = prices[i] - min_price;
//         if(today_sell_profit > max_profit){
//             max_profit = today_sell_profit;
//         }
//     }
//     return max_profit;
// }

int main(){
    //leetcode 121
    vector<int> prices{7,1,5,3,6,4};
    cout << maxProfit(prices);

    return 0;
}