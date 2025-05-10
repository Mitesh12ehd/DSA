#include<iostream>
#include<vector>
using namespace std;

//Leetcode 55
//Jump game

//recursive solution
//try out every combination of jump
//time = O(n^n)
//space = O(n)
bool helper(int index,vector<int>& nums){
    if(index >= nums.size()-1){
        return true;
    }

    for(int i=1; i<=nums[index]; i++){
        if(helper(index+i,nums)){
            return true;
        }
    }
    return false;
}
bool canJump(vector<int>& nums) {
    return helper(0,nums);
}

//better approach
//using dp see later
//time = O(n^2)
//space = O(n^2)

//optimal solution
//think greedy and jump the maximum 
//and maintain maximum point we can reach 
//dryrun on [1,2,4,1,1,0,2,5]

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxi = 0;
    for(int i=0; i<n-1; i++){
        if(i > maxi){
            return false;
        }
        maxi = max(maxi,i + nums[i]);
    }
    return maxi >= n-1;
}

int main(){
    return 0;
}