#include<iostream>
#include<vector>
using namespace std;

// Leetcode 300
// Longest Increasing Subsequence

// recursion
// time = O(2^n)
// space = O(n)
/*
 - we need to carry two variable
        1. index 2. last included index
 ->   fun(index,last_included_index)
      denote length of LIS in arr[index.....n-1] where prev included element 
      is at last_included_index
*/
int fun(int index,int last_included_index,vector<int>& nums){
    //base case
    if(index == nums.size()){
        return 0;
    }

    //exclude
    int exclude = fun(index+1,last_included_index,nums);

    //include
    int include = 0;
    if(last_included_index == -1 || nums[index] > nums[last_included_index]){
        include = 1 + fun(index+1,index,nums);
    }
    return max(exclude,include);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return fun(0,-1,nums);
}

// memorization
/*
 -> two changing varible
    index : 0 to n-1
    lastIndex : -1 to n-1

    - here we can't access -1 in dp table
    - so that we shift last index in dp table only,
       -1 become 0
       0 become 1
       n-1 become n
*/
// time = O(n^2)
// space = O(n^2 + n)
int fun(int index,int last_included_index,vector<int>& nums,vector<vector<int>>& dp){
    //base case
    if(index == nums.size()){
        return 0;
    }
    if(dp[index][last_included_index + 1] != -1){
        return dp[index][last_included_index + 1];
    }

    //exclude
    int exclude = fun(index+1,last_included_index,nums,dp);

    //include
    int include = 0;
    if(last_included_index == -1 || nums[index] > nums[last_included_index]){
        include = 1 + fun(index+1,index,nums,dp);
    }
    dp[index][last_included_index + 1] = max(exclude,include);
    return dp[index][last_included_index + 1];
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return fun(0,-1,nums,dp);
}

// tabulation
/*
   - in base case we go index == n
   - so we need n+1 * n+1 size dp array
   - in base case we intialize something 0, so that we can directy intilize array with
     all 0 and we don't need to write base case.
*/
// time = O(n^2)
// space = O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //in just dp, we represent lastindex to lastindex+1
    //in nums array lastindex remains lastindex
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    //logic
    for(int index=n-1; index>=0; index--){
        for(int lastIndex=n-1; lastIndex>=-1; lastIndex--){
            //exclude
            int exclude = dp[index+1][lastIndex + 1];

            //include
            int include = 0;
            if(lastIndex == -1 || nums[index] > nums[lastIndex]){
                include = 1 + dp[index+1][index+1];
            }
            dp[index][lastIndex + 1] = max(exclude,include);
        }
    }
    return dp[0][0];
}  

// space optimization 1
// time = O(n^2)
// space = O(2n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> nextRow(n+1,0);
    vector<int> currRow(n+1,0);

    //logic
    for(int index=n-1; index>=0; index--){
        for(int lastIndex=n-1; lastIndex>=-1; lastIndex--){
            //exclude
            int exclude = nextRow[lastIndex + 1];

            //include
            int include = 0;
            if(lastIndex == -1 || nums[index] > nums[lastIndex]){
                include = 1 + nextRow[index+1];
            }
            currRow[lastIndex + 1] = max(exclude,include);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// space optimization 2
// time = O(n^2)
// space = O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> nextRow(n+1,0);

    //logic
    for(int index=n-1; index>=0; index--){
        for(int lastIndex=-1; lastIndex<=n-1; lastIndex++){
            //exclude
            int exclude = nextRow[lastIndex + 1];

            //include
            int include = 0;
            if(lastIndex == -1 || nums[index] > nums[lastIndex]){
                include = 1 + nextRow[index+1];
            }
            nextRow[lastIndex + 1] = max(exclude,include);
        }
        nextRow = nextRow;
    }
    return nextRow[0];
}

int main(){
    return 0;
}