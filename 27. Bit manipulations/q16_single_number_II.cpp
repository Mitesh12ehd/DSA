#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Leetcode 137
//Single number II

// see notes 

//brute force will be store freq in map
//and find which element in map have freq = 1

//better approach time = O(32*n)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int bitIndex=0; bitIndex<32; bitIndex++){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            //check bit is 1 or not in nums[i]
            if(nums[i] & (1 << bitIndex)){
                count++;
            }
        }

        if(count % 3 == 1){
            //set ith bit in answer
            ans = ans | (1 << bitIndex);
        }
    }
    return ans;
}

//optimal approach 
//time = O(nlogn + n/3)
//space = O(1)
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    for(int i=1; i<nums.size(); i=i+3){
        if(nums[i] != nums[i-1]){
            return nums[i-1];
        }
    }
    //this statement execute only when answer is present at the end of array
    return nums[nums.size()-1];
}

//most optimal approach 
int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for(int i=0; i<nums.size(); i++){
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main(){
    return 0;
}