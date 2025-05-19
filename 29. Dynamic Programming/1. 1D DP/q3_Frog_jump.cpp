#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//GFG
//Frog jumps

//see notes

//recursion
int fun(int index,vector<int>& height){
    if(index == 0){
        return 0;
    }

    int prevCost = fun(index-1,height) + abs(height[index] - height[index-1]);
    int prev2Cost = INT_MAX;
    if(index > 1){
        prev2Cost = fun(index-2,height) + abs(height[index] - height[index-2]);
    }
    return min(prevCost,prev2Cost);
}
int minCost(vector<int>& height) {
    if(height.size() <= 1){
        return 0;
    }
    return fun(height.size()-1,height);
}

//memorization
int fun(int index, vector<int>& height,vector<int>& dp){
    if(index == 0){
        return 0;
    }   
    if(dp[index] != -1){
        return dp[index];
    }

    int prevCost = fun(index-1,height,dp) + abs(height[index] - height[index-1]);
    int prev2Cost = INT_MAX;
    if(index > 1){
        prev2Cost = fun(index-2,height,dp) + abs(height[index] - height[index-2]);
    }   
    dp[index] = min(prevCost,prev2Cost);
    return dp[index];
}
int minCost(vector<int>& height) {
    if(height.size() <= 1){
        return 0;
    }
    vector<int> dp(height.size()+1,-1);
    return fun(height.size()-1,height,dp);
}

//tabulation
int minCost(vector<int>& height) {
    int n = height.size();

    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int index=1; index<n; index++){
        int prevCost = dp[index-1] + abs(height[index] - height[index-1]);
        int prev2Cost = INT_MAX;
        if(index > 1){
            prev2Cost = dp[index-2] + abs(height[index] - height[index-2]);
        }   
        dp[index] = min(prevCost,prev2Cost);
    }
    return dp[n-1];
}

//space optimization
int minCost(vector<int>& height) {
    int n = height.size();
    if(n <= 1){
        return 0;
    }

    int prevCost = 0;
    int prev2Cost = 0;
    for(int index=1; index<n; index++){
        int temp1 = prevCost + abs(height[index] - height[index-1]);
        int temp2 = INT_MAX;
        if(index > 1){
            temp2 = prev2Cost + abs(height[index] - height[index-2]);
        }

        int currCost = min(temp1,temp2);
        prev2Cost = prevCost;
        prevCost = currCost;
    }
    return prevCost;
}

int main(){
    return 0;
}