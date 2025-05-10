#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Leetcode 45
//Jump game II

//arr[] = {2,3,1,4,1,1,1,2}
//Each element nums[i] represents the maximum length of a forward jump 
//      from index i
//find the minimum number of jumps to reach last element of array
//given test case such that we can always reach last element of array
//      we can take nums[i]

//brute force
//time = O(n^n)
//space = O(n)
void helper(int index,int jumps,int& ans,vector<int>& nums){
    if(index >= nums.size()-1){
        ans = min(ans,jumps);
        return;
    }

    for(int i=index+1; i<=index+nums[index]; i++){
        helper(i,jumps+1,ans,nums);
    }
}
int jump(vector<int>& nums) {
    int ans = INT_MAX;
    helper(0,0,ans,nums);
    return ans;
}

//better approach using dp
//time = O(n^2)
//space = O(n^2)

//optimal approach see notes
//dryrun on {2,3,1,4,1,1,1,2}
int jump(vector<int>& nums) {
    int n = nums.size();

    int left = 0;
    int right = 0;
    int jumps = 0;
    while(right < n-1){
        int max_we_can_go = 0;
        for(int i=left; i<=right; i++){
            max_we_can_go = max(max_we_can_go,i+nums[i]);
        }

        //new range
        left = right+1;
        right = max_we_can_go;
        jumps++;
    }
    return jumps;
}


int main(){
    return 0;
}