#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Leetcode 416
// Partition equals subset sum

/*
Observation : 
    - we need to divide array into excatly two part
    - so that sum1 == sum2 == (totalSum / 2)
    - if totalSum is odd that we can't divide array
    
    - we are looking for array with target = (totalSum / 2);
    - so question can be check if subset exist with sum = (totalsum / 2) ?

    - edge case :  
        what is array have element that is larger than (totalSum / 2)?
        - then we can't divide array, return false
        - ex. arr = [100,4,6] 
*/

//time = O(n*totalsum/2);
//space = O(totalSum/2);
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prevRow(sum+1,false);

    //base case
    prevRow[0] = true;
    //second base case give true only when arr[index]==target
    prevRow[arr[0]] = true; 

    //write logic in terms of loops
    for(int index=1; index<n; index++){
        vector<bool> currRow(sum+1,false);
        currRow[0] = true;
        for(int target=0; target<=sum; target++){
            bool exclude = prevRow[target];
            bool include = false;
            if(target >= arr[index]){
                include = prevRow[target-arr[index]];
            }
            currRow[target] = include || exclude; 
        }
        prevRow = currRow;
    }
    return prevRow[sum];
}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    int maxi = INT_MIN;
    for(auto it:nums){
        totalSum += it;
        maxi = max(maxi,it);
    }
    if(totalSum % 2 == 1){
        return false;
    }
    int target = totalSum / 2;
    if(target < maxi){
        return false;
    }
    return isSubsetSum(nums,target);
}

int main(){
    return 0;
}