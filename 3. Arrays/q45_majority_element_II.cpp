#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//leetcode 229
//majority element II

//there can be at most 2 element that appear more than (floor of n/3) time

//brute force time = n^2
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        //here we check if it is first or second element of answer
        if(ans.size() == 0 || ans[0] != nums[i]){
            int count = 0;
            for(int j=0; j<n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > (n/3)){
                ans.push_back(nums[i]);
            }
        }
    }
    return ans;  
}

//extra space
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mp;
    for(auto it:nums){
        mp[it]++;
    }
    vector<int> ans;
    for(auto it:mp){
        if(it.second > (n/3)){
            ans.push_back(it.first);
        }
    }
    return ans;
}

//optimal moore voting algorithm time = O(n)
// edge case
// [2,1,1,3,1,4,5,6]
// here when we reach at index = 4 nums[i] = 1;
// ele2 contain 1 and we also update ele1 = 1 which is wrong
// so we include extra condition to avoid duplication

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1,ele2;

    for(int i=0; i<n; i++){
        if(cnt1 == 0 && nums[i] != ele2){
            cnt1++;
            ele1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != ele1){
            cnt2++;
            ele2 = nums[i];
        }
        else if(nums[i] == ele1){
            cnt1++;
        }
        else if(nums[i] == ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0;
    cnt2=0;
    for(int i=0; i<n; i++){
        if(nums[i] == ele1){
            cnt1++;
        }
        else if(nums[i] == ele2){
            cnt2++;
        }
    }
    vector<int> ans;
    if(cnt1 > (n/3)){
        ans.push_back(ele1);
    }
    if(cnt2 > (n/3)){
        ans.push_back(ele2);
    }
    return ans;
}

int main(){
    

    return 0;
}