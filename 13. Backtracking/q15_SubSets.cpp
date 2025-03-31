#include<iostream>
#include<vector>
using namespace std;

//leetcode 78
void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int>& output,int i){
    if(i >= nums.size()){
        ans.push_back(output);
        return;
    }

    //include
    output.push_back(nums[i]);
    helper(nums,ans,output,i+1);
    output.pop_back();

    //exclude
    helper(nums,ans,output,i+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int i=0;
    helper(nums,ans,output,i);
    return ans; 
}

int main(){
    return 0;
}