#include<iostream>
#include<vector>
using namespace std;

//Leetcode 90
//Subsets II

//watch striver video to understand

//brute force
//apply same approach as subsets question
//store subsets in set
//now create answer from set
//time = O(2^n + 2^n*log(2^n)) 
//space = O(2^n + n) for set + recursive space

//optimize
// ex. nums = (1,2,2,2,3,3)
//dryrun fully on this example to understand
//and go level wise during dryrun not depth for better understanding

void helper(vector<int>& nums,vector<int>& v,int i,vector<vector<int>>& ans){
    ans.push_back(v);

    for(int m=i; m<nums.size(); m++){
        if(m > i && nums[m] == nums[m-1]){
            continue;
        }

        v.push_back(nums[m]);
        helper(nums,v,m+1,ans);
        v.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int i=0;
    vector<int> v;
    vector<vector<int>> ans;
    helper(nums,v,i,ans);
    return ans;
}

int main(){
    return 0;
}