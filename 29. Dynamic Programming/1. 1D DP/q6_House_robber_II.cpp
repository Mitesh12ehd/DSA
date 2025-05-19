#include<iostream>
#include<vector>
using namespace std;

// Leetcode 213
// House robber II

// see notes

//optimized code for maximum sum of non adjacent element
int houseRobber(vector<int>& nums,int start,int end) {
    int n = end-start+1;
    
    //this amount is take based on we stand at index=1
    int prevIndexAmount = nums[start];
    int prev2IndexAmount = 0; 

    for(int index=start; index<=end; index++){
        int inclusionSum = nums[index];
        if(index-2 >= start){
            inclusionSum += prev2IndexAmount;
        }
        int exclusionSum = prevIndexAmount;

        int currIndexAmount = max(inclusionSum,exclusionSum);
        prev2IndexAmount = prevIndexAmount;
        prevIndexAmount = currIndexAmount;
    }
    return prevIndexAmount;
}
int rob(vector<int>& nums) {
    int n = nums.size();

    if(nums.size() == 1){
        return nums[0];
    }
    int ans1 = houseRobber(nums,1,n-1);
    int ans2 = houseRobber(nums,0,n-2);
    return max(ans1,ans2);
}

int main(){
    return 0;
}