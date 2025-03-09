#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;

//leetcode 1283 
//Find the smallest Divisor given a thresold

int findSumOfResult(vector<int> nums,int divisor){
    int sum = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int result = ceil((double)nums[i] / (double)divisor);
        sum = sum + result;
    }
    return sum;
}

//brute force time = O(maxi * n)
int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi = *max_element(nums.begin(),nums.end());
    //there is no answer after maxi because after that,
    //sum of result become same as maxi as dividor
    for(int i=1; i<=maxi; i++){
        int sum = findSumOfResult(nums,i);
        if(sum <= threshold){
            return i;
        }
    }
    return -1;
}

//optimal time = O(log(maxi) * n)
int smallestDivisor(vector<int>& nums, int threshold) {
    int start = 1;
    int end = *max_element(nums.begin(),nums.end());
    //there is no answer after maxi because after that,
    //sum of result become same as maxi as dividor
    int ans = INT_MAX;
    while(start<=end){
        int mid = (start+end)/2;
        
        int sum = findSumOfResult(nums,mid);
        if(sum <= threshold){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    return 0;
}