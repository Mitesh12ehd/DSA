#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// GFG
// Print longest increasing subsequence

// see notes

// first let's solve length of LIS problem using one more space optimized approach
// see notes and dryrun
// time = O(n^2)
// space = O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    
    int ans = 1;
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(dp[i],1 + dp[prev]);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

//Print LIS
//see notes and dryrun
//time = O(n^2)
//space = O(n)
vector<int> getLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    
    int maxLength = 1; //indicate index where LIS ends
    int lastIndex = 0; //indicate last index of
    for(int i=0; i<n; i++){
        hash[i] = i; // intialize hash array

        for(int prev=0; prev<i; prev++){
            if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if(dp[i] > maxLength){
            maxLength = dp[i];
            lastIndex = i;
        }
    }
    
    //create ans
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    return 0;
}