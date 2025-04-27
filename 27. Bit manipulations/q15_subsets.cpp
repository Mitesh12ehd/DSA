#include<iostream>
#include<vector>
using namespace std;

//Leetcode 78
//Subsets

//see notes

//this can be solved using recursion and we have done it in recursion
//explore that solution also

// time = O(2^n * n)
// space = O(2^n * n)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = 1 << nums.size();  // 1<<nums.size() equals 2^nums.size()

    for(int num=0; num<n; num++){
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(num & (1 << i)){
                v.push_back(nums[i]);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

int main(){
    return 0;
}