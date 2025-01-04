#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 2563
//count the number of fair pairs

//brute force
// long long countFairPairs(vector<int>& nums, int lower, int upper) {
//     long long ans = 0;
//     int n = nums.size();
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             int sum = nums[i]+nums[j];
//             if(sum>=lower && sum<=upper){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }


//optimal
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(),nums.end());
    return helper(nums,upper+1) - helper(nums,lower);
}
long long helper(vector<int>& nums,int val){
    long long ans=0;
    int left = 0;
    int right = nums.size()-1;

    while(left<right){
        if(nums[left] + nums[right] < val){
            ans =  ans + right-left;
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}

int main(){
    

    return 0;
}