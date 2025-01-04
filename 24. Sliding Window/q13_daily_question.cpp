#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 2461
//maximum sum of distinct subarrays with length k

long long maximumSubarraySum(vector<int>& nums, int k) {
    long long ans = 0;
    int n = nums.size();
    int left=0;
    int right=0;
    unordered_map<int,int> hash;
    long long sum = 0;

    while(right < n){
        if(right-left+1 > k){
            sum = sum - nums[left];
            hash[nums[left]]--;
            left++;
        }

        //check if element is repeated
        while(hash[nums[right]] > 0){
            sum = sum - nums[left];
            hash[nums[left]]--;
            left++;
        }

        sum = sum + nums[right];
        hash[nums[right]]++;
        if(right-left+1 == k){
            ans = max(ans,sum);
        }
        right++; 
    }

    return ans;
}

int main(){
    return 0;
}