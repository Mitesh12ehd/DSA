#include<iostream>
#include<vector>
using namespace std;

//brute force n^2
// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int n=nums.size();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum = sum + nums[j];
//             if(sum  == goal){
//                 ans++;   
//             }
//         }
//     }
//     return ans;
// }

//time = O(2 * 2n) space = O(1)
int numSubarrays_with_less_or_equal_sum_goal(vector<int>& nums, int goal){
    if(goal < 0){
        return 0;
    }

    int n=nums.size();
    int ans = 0;
    int sum = 0;
    int left=0,right=0;

    while(right < n){
        sum = sum + nums[right];
        while(sum > goal){
            sum = sum - nums[left];
            left++;
        }
        ans = ans + (right-left+1);
        right++;
    }
    return ans;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int a = numSubarrays_with_less_or_equal_sum_goal(nums,goal);
    int b = numSubarrays_with_less_or_equal_sum_goal(nums,goal-1);
    return a - b;
}



int main(){
    vector<int> nums = {1,0,0,1,1,0};
    int goal = 2;
    cout << numSubarraysWithSum(nums,goal);

    return 0;
}