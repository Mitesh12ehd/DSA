#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printAllPermutationsHelper(vector<int>& nums,int i,vector<vector<int>>& ans)
{
    //base case
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }

    unordered_map<int,bool> visited;
    for(int j=i; j<nums.size(); j++){
        if(visited.find(nums[j]) != visited.end()){
            continue;
        }
        visited[nums[j]] = true;
        //swap
        swap(nums[i],nums[j]);
        //recursive call
        printAllPermutationsHelper(nums,i+1,ans);
        //backtracking
        swap(nums[i],nums[j]);
    }
}
vector<vector<int>> printAllPermutations(vector<int>& nums) {
    vector<vector<int>> ans;
    printAllPermutationsHelper(nums,0,ans);
    return ans;
}
int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> ans = printAllPermutations(nums);
    for(auto it:ans){
        for(auto it1:it){
            cout << it1 <<" ";
        }
        cout << endl;
    }
    return 0;
}