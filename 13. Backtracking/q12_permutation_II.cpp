#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

//method 1
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

//method 2 easiest hand made = time = O(n!) space = O(n!)
void helper(vector<int>& nums,set<vector<int>>& ans,int i){
    int n = nums.size();
    //base case
    if(i == n-1){
        ans.insert(nums);
        return;
    }

    for(int j=i; j<n; j++){
        swap(nums[i],nums[j]);
        helper(nums,ans,i+1);
        swap(nums[i],nums[j]);
    }    
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int i=0;
    set<vector<int>> ans;

    helper(nums,ans,i);
    
    vector<vector<int>> finalAns;
    for(auto it:ans){
        finalAns.push_back(it);
    }
    return finalAns;
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