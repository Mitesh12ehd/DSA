#include<iostream>
#include<limits.h>
#include<cmath>
#include<vector>
using namespace std;

//Time O(n^n), Space O(n) method 1
int numSquares(int n) {
    //base case
    if(n <= 0){
        return 0;
    }
    
    int ans = INT_MAX;
    int i = 1;
    while(i*i <= n){
        int perfectSquare = i*i;
        int numberOfPerfectSquare = 1 + numSquares(n - perfectSquare);
        ans = min(ans,numberOfPerfectSquare);
        i++;
    }
    return ans;
}

//method 2
int minimumCoin(vector<int>& coins,int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = minimumCoin(coins,target-coins[i]);
        if(ans != INT_MAX){
            mini = min(mini,ans+1);
        }
    }
    return mini;
}
int numSquares(int n) {
    vector<int> perfectSquare;
    int num = 1;
    while(num * num <= n){
        perfectSquare.push_back(num * num);
        num++;
    }

    //coin change problem
    int ans = minimumCoin(perfectSquare,n);
    return ans;
}

int main(){
    int n = 12;
    cout << numSquares(n);

    return 0;
}