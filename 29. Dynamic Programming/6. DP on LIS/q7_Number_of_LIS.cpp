#include<iostream>
#include<vector>
using namespace std;

// Leetcode 673
// Number of Longest Increasing Subsequence

// see notes and do a proper dryrun on example
// nums = [1,5,4,3,2,6,7,10,8,9]
 
// Prerequisite :  print LIS

// time = O(n^2)

// space = O(n)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> count(n,1);
    
    int maxi = 1;
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(nums[prev] < nums[i] && dp[prev]+1 > dp[i]){
                //length of lis are update so that count remain same as count[prev]
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if(nums[prev] < nums[i] && dp[prev]+1 == dp[i]){
                //length of lis is not update, so that count of lis with same 
                //  length increseas
                count[i] = count[i] + count[prev];
            }
        }
        maxi = max(maxi,dp[i]);  
    }
    
    //count longest increasing subsequence
    int ans = 0;
    for(int i=0; i<n; i++){
        if(dp[i] == maxi){
            ans = ans + count[i];
        }
    }
    return ans;
}

int main(){
    return 0;
}