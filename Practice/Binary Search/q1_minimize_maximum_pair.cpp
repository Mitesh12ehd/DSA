#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Leetcode 2616
// Minimize the Maximum Difference of Pairs

//This method checks can we form p pair such that
// difference between elements of pais in <= mid
bool canFormPair(vector<int>& nums,int p, int mid){
    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++){
        if(nums[i] - nums[i-1] <= mid){
            count++;
            i++; //skip 1 element
        }
    }
    return count;
}
int minimizeMax(vector<int>& nums, int p) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    
    int start = 0;
    int end = nums[n-1] - nums[0];
    int ans = 0;

    while(start <= end){
        int mid = (start+end)/2;
        if(canFormPair(nums,p,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    return 0;
}