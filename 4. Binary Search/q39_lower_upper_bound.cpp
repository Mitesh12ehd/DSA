#include<iostream>
#include<vector>
using namespace std;

//both question are on GFG

// note : lower and upper bound doesn't means just smaller and just larget element, 
//        read both defination on GFG

int lowerBound(vector<int>& nums,int ele){
    int n = nums.size();
    int start = 0;
    int end = n-1;

    int ans = n;
    while(start <= end){
        int mid = (start+end) / 2;
        if(nums[mid] >= ele){
            ans = mid;
            end = mid - 1;
        }
        else{               
            start = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>& nums, int ele) {
    int n = nums.size();
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = (start+end)/2;
        if(nums[mid] > ele){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return start;
}

int main(){
    return 0;
}