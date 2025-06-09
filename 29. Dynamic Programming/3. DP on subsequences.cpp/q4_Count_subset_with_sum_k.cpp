#include<iostream>
#include<vector>
using namespace std;

//GFG
//Perfect sum problem

/*
    How this question in different from previous three question? 
    - in previous three question we need to find out is sum possible?
    - but here we need to find number of subset that can form given sum
*/

//recursion
//time = O(2^n)
//space = O(n)
/*
    1. express in terms of index
    2. explore all possible path, here exclude include
    3. sum of count
 
    fun(n-1,sum) = number of subset from index 0 to n-1 that have given sum
*/
int fun(int index,int sum,vector<int>& arr){
    if(index == 0){
        if(sum == 0 && arr[0] == 0){
            //count 0 by include it and exclude it
            return 2;
        }
        if(sum == 0){
            return 1;
        }
        if(sum == arr[index]){
            return 1;
        }
        return 0;
    }

    //exclude
    int exclude = fun(index-1,sum,arr);
    //include
    int include = 0;
    if(sum >= arr[index]){
        include = fun(index-1,sum-arr[index],arr);
    }
    return exclude + include;   
}
int perfectSum(vector<int>& arr, int target) {
    return fun(arr.size()-1,target,arr);
}

//memorization
//time = O(n*target)
//space = O(n*target + n)
int fun(int index,int sum,vector<int>& arr,vector<vector<int>>& dp){
    if(index == 0){
        if(sum == 0 && arr[0] == 0){
            //count 0 by include it and exclude it
            return 2;
        }
        if(sum == 0){
            return 1;
        }
        if(sum == arr[index]){
            return 1;
        }
        return 0;
    }
    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    //exclude
    int exclude = fun(index-1,sum,arr,dp);
    //include
    int include = 0;
    if(sum >= arr[index]){
        include = fun(index-1,sum-arr[index],arr,dp);
    }
    dp[index][sum] = exclude + include;  
    return dp[index][sum]; 
}
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return fun(n-1,target,arr,dp);
}

//tabulation
//time = O(n*target)
//space = O(n*target)
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    
    //base case
    for(int sum=0; sum<=target; sum++){
        if(sum == 0 && arr[0] == 0){
            //count 0 by include it and exclude it
            dp[0][sum] = 2;
        }
        else if(sum == 0){
            dp[0][sum] = 1;
        }
        else if(sum == arr[0]){
            dp[0][sum] = 1;
        }
        else{
            dp[0][sum] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        for(int sum=0; sum<=target; sum++){
            //exclude
            int exclude = dp[index-1][sum];
            //include
            int include = 0;
            if(sum >= arr[index]){
                include = dp[index-1][sum-arr[index]];
            }
            dp[index][sum] = exclude + include;  
        }
    }
    return dp[n-1][target];
}

//space optimization
//time = O(n*target)
//space = O(target)
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> prevRow(target+1,-1);
    
    //base case
    for(int sum=0; sum<=target; sum++){
        if(sum == 0 && arr[0] == 0){
            //count 0 by include it and exclude it
            prevRow[sum] = 2;
        }
        else if(sum == 0){
            prevRow[sum] = 1;
        }
        else if(sum == arr[0]){
            prevRow[sum] = 1;
        }
        else{
            prevRow[sum] = 0;
        }
    }

    //logic
    for(int index=1; index<n; index++){
        vector<int> currRow(target+1,-1);
        for(int sum=0; sum<=target; sum++){
            //exclude
            int exclude = prevRow[sum];
            //include
            int include = 0;
            if(sum >= arr[index]){
                include = prevRow[sum-arr[index]];
            }
            currRow[sum] = exclude + include;  
        }
        prevRow = currRow;
    }
    return prevRow[target];
}

int main(){
    return 0;
}