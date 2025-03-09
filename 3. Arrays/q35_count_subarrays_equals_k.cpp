#include<iostream>
#include<vector>
#include<unordered_map>
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


//prefix sum with frequency concept
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int prefix = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;

    for(int i=0; i<n; i++){
        prefix = prefix + nums[i];
        if(mp.find(prefix-k) != mp.end()){
            ans = ans + mp[prefix-k];
        }
        mp[prefix]++;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    cout << subarraySum(arr,k);

    return 0;
}