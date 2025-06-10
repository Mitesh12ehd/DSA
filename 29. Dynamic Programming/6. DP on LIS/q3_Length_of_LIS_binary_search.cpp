#include<iostream>
#include<vector>
using namespace std;

// Leetcode 300
// Longest Increasing Subsequence

// see notes

// time = O(nlogn)
// space = O(n)
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
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> sequence;

    for(int i=0; i<n; i++){
        int insertIndex = lowerBound(sequence,nums[i]);
        if(insertIndex == sequence.size()){
            sequence.push_back(nums[i]);
        }
        else{
            sequence[insertIndex] = nums[i];
        }
    }
    return sequence.size();
}

int main(){
    return 0;
}