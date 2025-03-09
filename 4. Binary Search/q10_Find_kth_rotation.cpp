#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//gfg
//find kth rotation

//find how many time array is rotated
//index where minimum element present = array rotated (index) time

//extra - if array have duplicates 
//handle it by logic of rotated sorted array II

int findKRotation(vector<int> &nums) {
    int start = 0;
    int end = nums.size()-1;
    int mini = INT_MAX;
    int ans = -1;

    while(start<=end){
        int mid = start + (end-start)/2;

        //left part is sorted
        if(nums[start] <= nums[mid]){
            if(nums[start] < mini){
                mini = nums[start];
                ans = start;
            }

            //now try to find from right half because we considered minimum of left half
            start = mid+1;
        }
        //right part is sorted
        else{
            if(nums[mid] < mini){
                mini = nums[mid];
                ans = mid;
            }

            //now try to find from left half because we considered minimum of right half
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    return 0;
}