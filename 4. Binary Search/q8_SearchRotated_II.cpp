#include<iostream>
#include<vector>
using namespace std;

//search in rotated sorted array

//[3,1,2,3,3,3,3]
//here we can't decide which side to go because we don't know which side is sorted
//so we need to ignore when there is duplicate

//only problem is arr[start] = arr[mid] = arr[end]
//we have to get ridd off this condition

// time = O(log n) in average case
//      = O(n) in worst case
    
//     ex. [3,3,1,3,3,3,3]
//     here we keep shrinking util [1,3,3]
//     so that it taked O(n/2) time

// space = O(1)
 
int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;

    while(start<=end){
        int mid = start + (end-start) / 2;

        if(nums[mid] == target){
            return true;
        }
        //get ridd of given condition
        else if(nums[start] == nums[mid] && nums[mid] == nums[end]){
            start++,end--;
            continue;
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
            //make sure element may present inside [end,mid]
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
    return 0;
}