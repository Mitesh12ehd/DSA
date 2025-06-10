#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 368
// Largest Divisible Subset

// Prerequisite : q2_Print_LIS

/*
    Subset : we can write element in any order
    ex. for arr = [1,16,7,8,4]
        {1,8,16} is valid subset

    ex. arr = {16,8,4}
    - here we have subset that follow divisable property arr[j] % arr[i] == 0 
      or arr[i] % arr[j] == 0
    - {16,8} {16,4} {8,4} {16,8,4} {16} {8} {4}
    - we need to find largest subset
*/

/*
    - if we sort array our answer won't be changes because of subset property
    
    - how we ensure that each element in subset is divisable?
      ex. arr = [1,4,7,8,16]
          we have stored [1,4] in subset
          now we are at index 3, ele = 8
          
          - at 8 we have subset [1,4]
          - if 4 is divisable by 1,
            if 8 is divisable by 4
            then 8 is also divisable by 1
          - our subset will be [1,4,8]

          - at 16 we have subset [1,4,8]
          - 16 is divisable by 8 hence,
            16 is also divisable by all previous element in subsets
        
          - this nature comes from sorted array
          - our answer will be [1,4,8,16]

    - we can map this questin with print LIS
      in that question we check current element is larger than previous or not?
      here we are checking current element is divisable by previous or not?
*/

// time = O(n^2)
// space = O(n)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> hash(n);

    sort(nums.begin(),nums.end());
    
    int maxLength = 1;
    int lastIndex = 0;
    for(int i=0; i<n; i++){
        hash[i] = i; // intialize hash array

        for(int prev=0; prev<i; prev++){
            if(nums[i] % nums[prev] == 0 && 1+dp[prev] > dp[i]){
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
    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    return ans;
}

int main(){
    return 0;
}