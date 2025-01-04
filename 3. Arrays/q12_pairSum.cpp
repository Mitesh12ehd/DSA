#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//time = O(n^2) space = O(1)
int getPairsCount(int arr[], int n, int k) {
    // code here
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == k){
                ans++;
            }
        }
    }
    return ans;
}

//time = O(n) space = O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        int remaining = target-nums[i];
        if(mp.find(remaining) != mp.end()){
            ans.push_back(mp[remaining]);
            ans.push_back(i);
        }
        mp[nums[i]] = i;
    }
    return ans;
}

//two pointer work if we not have to return index time = O(nlogn) , space = O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    sort(nums.begin(),nums.end());

    int start = 0;
    int end = nums.size()-1;
    while(start < end){
        if(nums[start] + nums[end] == target){
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
        else if(nums[start] + nums[end] < target){
            start++;
        }
        else if(nums[start] + nums[end] > target){
            end--;
        }
    }

    return ans;
}

int main(){
    //leetcode 1
    int arr[] = {1,3,5,7,2,4,6};
    int sum = 9;
    int n =  7; 
    

    return 0;
}