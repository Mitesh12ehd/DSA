#include<iostream>
#include<vector>
using namespace std;

//leetcode 162
//Find peak element

//brute force
int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    for(int i=0; i<n; i++){
        if(i==0){
            if(i+1 < n){
                if(nums[i] > nums[i+1]){
                    return i;
                }
            }
            else{
                return i;
            }
        }
        else if(i == n-1){
            if(i-1 >= 0){
                if(nums[i] > nums[i-1]){
                    return i;
                }
            }
            else{
                return i;
            }
        }
        else{
            if(nums[i] > nums[i+1] && nums[i] > nums[i+1]){
                return i;
            }
        }
    }
    return -1;
}

//optimal
int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n == 1){
        return 0;
    }
    if(nums[0] > nums[1]){
        return 0;
    }
    if(nums[n-1] > nums[n-2]){
        return n-1;
    }

    int start = 1;
    int end = n-2;

    while(start<=end){
        int mid = start + (end-start) / 2;

        if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
            return mid;
        }
        else if(nums[mid] > nums[mid-1]){
            //sequence is increasing, hence we stand at left of peak element
            //we need to go right
            start = mid+1;
        }
        // else if(nums[mid] > nums[mid+1]){
        //     //sequence is decreasing, hence we stand at right of peak element
        //     //we need to go left
        //     end = mid-1;
        // }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    return 0;
}