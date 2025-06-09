#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Leetcode 494
//Target sum

// This question is same as partition with given difference

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> prevRow(target+1,-1);
    
    //base case
    for(int sum=0; sum<=target; sum++){
        if(sum == 0 && arr[0] == 0){
            //count 0 by include it and exclude it
            prevRow[sum] = 2;
        }
        else if(sum == 0){
            prevRow[sum] = 1;
        }
        else if(sum == arr[0]){
            prevRow[sum] = 1;
        }
        else{
            prevRow[sum] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        vector<int> currRow(target+1,-1);
        for(int sum=0; sum<=target; sum++){
            //exclude
            int exclude = prevRow[sum];
            //include
            int include = 0;
            if(sum >= arr[index]){
                include = prevRow[sum-arr[index]];
            }
            currRow[sum] = exclude + include;  
        }
        prevRow = currRow;
    }
    return prevRow[target];
}
int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int totalSum = 0;
    for(auto it:arr){
        totalSum += it;
    }

    if(totalSum - d < 0){
        return 0;
    }
    if((totalSum-d) % 2 == 1){
        return 0;
    }
    int sum2 = (totalSum - d) / 2;
    return perfectSum(arr,sum2);
}
int findTargetSumWays(vector<int>& nums, int target) {
    return countPartitions(nums,target);
}

int main(){
    return 0;
}