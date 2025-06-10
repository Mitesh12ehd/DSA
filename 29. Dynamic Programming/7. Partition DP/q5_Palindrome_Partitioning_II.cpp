#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Leetcode 132
// Palindrome Partitioning II

// see notes

bool isPalindrome(int start,int end,string& s){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        start++,end--;  
    }
    return true;
}

// recursion
// time = O(2^n) because for each index, we either partition or not partition
// space = O(n)
int fun(int i,string& s){
    int n = s.length();
    if(i == n){
        return 0;
    }
    
    int minCost = INT_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(i,j,s)){
            int cost = 1 + fun(j+1,s);
            minCost = min(minCost,cost);
        }
    }
    return minCost;
}
int minCut(string s) {
    int n = s.length();
    return fun(0,s)-1;
}

// memorization
// time = O(n^3)
// space = O(n+n)
int fun(int i,string& s,vector<int>& dp){
    int n = s.length();
    if(i == n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    
    int minCost = INT_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(i,j,s)){
            int cost = 1 + fun(j+1,s,dp);
            minCost = min(minCost,cost);
        }
    }
    dp[i] = minCost;
    return dp[i];
}
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n,-1);
    return fun(0,s,dp) - 1;
}

// tabulation
// time = O(n^3)
// space = O(n+n)
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n+1,-1); //n+1 because of base case

    //base case
    dp[n] = 0;

    //logic
    for(int i=n-1; i>=0; i--){
        int minCost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0];
}

int main(){
    return 0;
}