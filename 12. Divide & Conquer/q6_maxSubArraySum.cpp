#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//method 1 brute force time = O(N^3)
int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int finalsum = INT_MIN;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum = sum + arr[k];
            }
            finalsum = max(finalsum,sum);
        }
    }
    return finalsum;
}

//method 2 brute force time = O(N^2)
int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int finalsum = INT_MIN;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum = sum + arr[j];
            finalsum = max(finalsum,sum);
        }
    }
    return finalsum;
}   

//to understand cross border sum dry run on
// {-2,1,-3,4,-1,2,1,-5,4}

int maxSubArrayHelper(vector<int>& arr,int start,int end){
    if(start == end){
        return arr[start];
    }

    int mid = start + (end-start)/2;
    int maxLeftSum = maxSubArrayHelper(arr,start,mid);
    int maxRightSum = maxSubArrayHelper(arr,mid+1,end);

    //max cross border sum
    int leftBorderSum = 0, rightBorderSum = 0;
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

    for(int i=mid; i>=start; i--){
        leftBorderSum = leftBorderSum + arr[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }   
    }
    for(int i=mid+1; i<=end; i++){
        rightBorderSum = rightBorderSum + arr[i];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(maxLeftSum,max(maxRightSum,crossBorderSum));
}

//method 3 - divide and conquer
int maxSubArray(vector<int>& arr) {
    return maxSubArrayHelper(arr,0,arr.size()-1); 
}

// method 4 kadane's algorithm time = O(n)
int maxSubArray(vector<int>& nums) {
    int maxi = INT_MIN;
    int sum = 0;

    for(int i=0; i<nums.size(); i++){
        sum = sum + nums[i];
        
        maxi = max(sum,maxi);
        
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

//follow up question : print subarray with largest sum
vector<int> print_maxSubArray(vector<int>& nums) {
    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = 0;

    for(int i=0; i<nums.size(); i++){
        if(sum = 0){
            ansStart = i;
        }

        sum = sum + nums[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        maxi = max(sum,maxi);
        
        if(sum < 0){
            sum = 0;
        }
    }

    vector<int> ans;
    for(int i=ansStart; i<=ansEnd; i++){
        ans.push_back(nums[i]);
    }
    return ans;
}


int main(){
    //leetcode 53
    vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(arr);

    return 0;
}