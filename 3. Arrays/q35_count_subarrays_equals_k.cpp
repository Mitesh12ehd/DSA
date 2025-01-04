#include<iostream>
#include<vector>
using namespace std;

//brute force n^2
// int subarraySum(vector<int>& nums, int k) {
//     int n = nums.size();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum = sum + nums[j];
//             if(sum == k){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }


int subarraySum(vector<int>& nums, int k) {
    
}

int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    cout << subarraySum(arr,k);

    return 0;
}