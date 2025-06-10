#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 1043
// Partition Array for Maximum Sum

// see notes

// recursion
// time = O(2^n)
// space = O(n)
int fun(int i,vector<int>& arr,int k){
    int n = arr.size();
    if(i == n){
        return 0;
    }
    
    int maxAns = 0;
    int maxEle = INT_MIN;
    int len = 0;
    for(int j=i; j<i+k && j<n; j++){
        len++;
        maxEle = max(maxEle,arr[j]);
        int sum = (maxEle * len) + fun(j+1,arr,k);
        maxAns = max(maxAns,sum);
    }
    return maxAns;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    return fun(0,arr,k);
}

// memorization
// time = O(n*k)
// space = O(n+n)
int fun(int i,vector<int>& arr,int k,vector<int>& dp){
    int n = arr.size();
    if(i == n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    
    int maxAns = 0;
    int maxEle = INT_MIN;
    int len = 0;
    for(int j=i; j<i+k && j<n; j++){
        len++;
        maxEle = max(maxEle,arr[j]);
        int sum = (maxEle * len) + fun(j+1,arr,k,dp);
        maxAns = max(maxAns,sum);
    }
    dp[i] = maxAns;
    return dp[i];
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n,-1);
    return fun(0,arr,k,dp);
}

// tabulation
// time = O(n*k)
// space = O(n)
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1,0); //size is n+1 because in base case we access dp[n]

    //base case
    dp[n] == 0;

    //logic
    for(int i=n-1; i>=0; i--){
        int maxAns = 0;
        int maxEle = INT_MIN;
        int len = 0;
        for(int j=i; j<i+k && j<n; j++){
            len++;
            maxEle = max(maxEle,arr[j]);
            int sum = (maxEle * len) + dp[j+1];
            maxAns = max(maxAns,sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}

int main(){
    return 0;
}