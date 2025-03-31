#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode 260
//Single number III

//brute force will be using hashmaps
vector<int> singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    int currNum = nums[0];
    int count = 1;
    vector<int> ans;
    for(int i=1; i<nums.size(); i++){
        if(count == 2){
            currNum = nums[i];
            count = 1;
        }
        else if(nums[i] != currNum){
            ans.push_back(currNum);
            currNum = nums[i];
            count = 1;
        }
        else{
            count++;
        }
    }
    return ans;
}

//better approach time = O(nlogn) space = O(1)
vector<int> singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    int currNum = nums[0];
    int count = 1;
    vector<int> ans;
    for(int i=1; i<nums.size(); i++){
        if(count == 2){
            currNum = nums[i];
            count = 1;
        }
        else if(nums[i] != currNum){
            ans.push_back(currNum);
            currNum = nums[i];
            count = 1;
        }
        else{
            count++;
        }
    }

    if(count != 2){
        ans.push_back(currNum);
    }
    return ans;
}

//most optimal approach

//why overflow
//because if XOR becomes = INT_MIN;
//and we take XOR-1 , which int can't store

vector<int> singleNumber(vector<int>& nums) {
    long XOR = 0; 
    for(auto it:nums){
        XOR = XOR ^ it;
    }

    //this line gives number with rightmost bit set as 1
    int rightMost = (XOR & (XOR-1)) ^ XOR;
    int b1 = 0;
    int b2 = 0;
    for(auto it:nums){
        if((it & rightMost) != 0){
            b1 = b1 ^ it;
        }
        else{
            b2 = b2 ^ it;
        }
    }
    return {b1,b2};
}

int main(){
    return 0;
}