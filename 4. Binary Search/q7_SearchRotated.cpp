#include<iostream>
#include<vector>
using namespace std;

//search in rotated sorted array
//leetcode 33

//brute force can be done using linear search

//time = O(log n)
int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;

    while(start<=end){
        int mid = start + (end-start) / 2;

        if(nums[mid] == target){
            return mid;
        }
        //left part is sorted
        else if(nums[start] <= nums[mid]){
            //make sure element may present inside [start,mid]
            if(nums[start] <= target && target <= nums[mid]){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        //right part is sorted
        else{
            //make sure element may present inside [mid,end]
            if(nums[mid] <= target && target <= nums[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums{9,10,2,4,6,8};
    int target = 6;
    cout<<"answer = "<<search(nums,target);

    return 0;
}