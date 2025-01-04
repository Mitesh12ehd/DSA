#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//leetcode 922
//to optmize this problem we first solve another problem

//find the number of subarray that have at most k unique integer
//after solving this problem
//number of subarray with at most k unique charcter - 
//   number of subarray with at most k-1 unique charterw

//brute force time=O(N^2) space=O(N)
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    for(int i=0; i<n; i++){
        unordered_map<int,int> mp;
        for(int j=i; j<n; j++){
            mp[nums[j]]++;

            if(mp.size() == k){
                ans++;
            }
            else if(mp.size() > k){
                break;
            }
        }
    }
    return ans;
}

//time = O(2N) space = O(n)
int helper(vector<int>& nums,int k){
    if(k <= 0){
        return 0;
    }

    int n = nums.size();
    int ans = 0;
    int left = 0;
    int right = 0;
    unordered_map<int,int> mp;

    while(right < n){
        mp[nums[right]]++;

        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
            }
            left++;
        }

        if(mp.size() <= k){
            ans = ans + (right-left+1);    
        }
        right++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums,k) - helper(nums,k-1);
}

int main(){
    

    return 0;
}