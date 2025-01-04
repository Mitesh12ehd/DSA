#include<iostream>
#include<vector>
using namespace std;

//this problem is same is binary subaarray with sum problem
//optional intitution
//assume odd number as 1 and even as 0 and it become same as previous question

//brute force n^2
// int numberOfSubarrays(vector<int>& nums, int k) {
//     int ans = 0;
//     int n = nums.size();

//     for(int i=0; i<n; i++){
//         int oddcount = 0;
//         for(int j=i; j<n; j++){
//             if(nums[j] % 2){
//                 oddcount++;
//             }

//             if(oddcount == k){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

int helper(vector<int>& nums, int goal){
    if(goal < 0){
        return 0;
    }

    int n=nums.size();
    int ans = 0;
    int count = 0;
    int left=0,right=0;

    while(right < n){
        if(nums[right] % 2) count++;

        while(count > goal){
            if(nums[left] % 2){
                count--;
            }
            left++;
        }
        ans = ans + (right-left+1);
        right++;
    }
    return ans;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    int a = helper(nums,k);
    int b = helper(nums,k-1);
    return a - b;
}

int main(){
    return 0;
}