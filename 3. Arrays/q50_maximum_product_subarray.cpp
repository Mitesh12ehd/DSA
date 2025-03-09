#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 152
//Maximum product subarray

//brute force
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int product = 1;
        for(int j=i; j<n; j++){
            product = product * nums[j];
            ans=max(ans,product);
        }
    }
    return ans;
}

//optimal appraoch obervation based

// 1. if all element are positive, 
//     ans = multiplication of all element

// 2. if there is even number of nagative element,  
//     ans = multiplication of all element

// 3. if there is odd number of nagative element,
//     answer will be find by ignoring one nagative

//     ex. [3,2,-1,4,-6,3,-2,6]
//     if we ignore -1, ans = max( (3*2) , (4*-6*3*-2*6))
//     if we ignore -6, ans = max( (3*2*-1*4) , (3*-2*6))
//     if we ignore -2, ans = max( (3*2*-1*4*-6*3) , (6))

//    answer will be found by prefix or suffix

// 4. if there is 0 in the is_array
//     ex. [-2,3,4,-1,0,-2,3,1,4,0,4,6,-1,4]
//     ans = max( ans(-2,3,4,-1) , ans(-2,3,1,4) , ans(4,6,-1,4))

//     to handle 0 case we start prefix and suffix from 1 again and find answer

//to understand dryrun on various test case
//generate test case on your own

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;

    for(int i=0; i<n; i++){
        if(prefix == 0){
            prefix = 1;
        }
        prefix = prefix * nums[i];
        ans = max(ans,prefix);
    }
    for(int i=n-1; i>=0; i--){
        if(suffix == 0){
            suffix = 1;
        }
        suffix = suffix * nums[i];
        ans = max(ans,suffix);
    }
    return ans;
}

// note:also we can write in one loop

int main(){
    return 0;
}