#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(start == end){
            return start;
        }
        else if( mid+1<=end && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if( mid-1>=start && arr[mid] < arr[mid-1]){
            return mid-1;
        }
        else if(arr[start] > arr[mid]){
            //left
            end = mid-1;
        }
        else{
            //right
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int binarySearch(vector<int> arr,int start,int end,int target){
    int mid = start + (end-start)/2;   // mid = (start+end)/2
    while(start<=end){
        if(arr[mid] == target){
            return mid;
        }
        else if(target>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivotIndex = findPivot(nums);
    int ans = 0;
    if( target >= nums[0]  &&  target <= nums[pivotIndex]){
        //left search
        ans = binarySearch(nums,0,pivotIndex,target);
    }
    else{
        //right search
        ans = binarySearch(nums, pivotIndex+1, nums.size()-1, target);
    }
    return ans;
}

int main(){
    vector<int> nums{9,10,2,4,6,8};
    int target = 6;
    cout<<"answer = "<<search(nums,target);

    return 0;
}