#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 153
//find minimum in rotated sorted array

//brute force can be done using linear search

//O(logn)
int findMin(vector<int>& nums) {
    int start = 0;
    int end = nums.size()-1;
    int ans = INT_MAX;

    while(start<=end){
        int mid = start + (end-start)/2;

        //left part is sorted
        if(nums[start] <= nums[mid]){
            ans = min(ans,nums[start]);

            //now try to find from right half because we considered minimum of left half
            start = mid+1;
        }
        //right part is sorted
        else{
            ans = min(ans,nums[mid]);

            //now try to find from left half because we considered minimum of right half
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    return 0;
}