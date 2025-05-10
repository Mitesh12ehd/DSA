#include<iostream>
#include<vector>
using namespace std;

//GFG
//Minimum number of coins

//This question is not similar to coin change
//here we given fixed coins

//Why greedy works here?
//if we add any two smaller adjacent coin, it not exceed to it's next one
//it fails if coins = {1,5,6,9} N=11

//time = O(N) in worst case
//space = O(1)

vector<int> minPartition(int N){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;

    for(int i=coins.size() - 1; i>=0; i--){
        while(N >= coins[i]){
            ans.push_back(coins[i]);
            N = N - coins[i];
        }
    }
    return ans;
}

int main(){
    return 0;
}