#include<iostream>
#include<vector>
using namespace std;

//GFG
//Subset sum problem

//see notes
//dryrun to understand

//recursion
//time = O(2^n)
//space = O(n)
int fun(int index,int target,vector<int>& arr){
    if(target == 0){
        return true;
    }
    if(index == 0){
        return arr[0] == target;
    }

    //exclusion
    bool exclude = fun(index-1,target,arr);
    //inclusion 
    bool include = false;
    if(target >= arr[index]){
        include = fun(index-1,target-arr[index],arr);
    }
    return exclude || include;
}
bool isSubsetSum(vector<int>& arr, int sum) {
    return fun(arr.size()-1,sum,arr);
}

//memorization
//time = O(n*sum)
//space = O(n*sum + n)
int fun(int index,int target,vector<int>& arr,vector<vector<int>> dp){
    if(target == 0){
        return true;
    }
    if(index == 0){
        return arr[0] == target;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    //exclusion
    bool exclude = fun(index-1,target,arr,dp);
    //inclusion 
    bool include = false;
    if(target >= arr[index]){
        include = fun(index-1,target-arr[index],arr,dp);
    }
    dp[index][target] = exclude || include;
    return dp[index][target];
}
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return fun(arr.size()-1,sum,arr,dp);
}

//tabulation
//time = O(n*sum)
//space = O(n*sum)
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

    //base case
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    //second base case give true only when arr[index]==target
    dp[0][arr[0]] = 1; 

    //write logic in terms of loops
    for(int index=1; index<n; index++){
        for(int target=0; target<=sum; target++){
            bool exclude = dp[index-1][target];
            bool include = false;
            if(target >= arr[index]){
                include = dp[index-1][target-arr[index]];
            }
            dp[index][target] = include || exclude; 
        }
    }
    return dp[n-1][sum];
}

//space optimization
//time = O(n*sum)
//space = O(sum)
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prevRow(sum+1,false);

    //base case
    prevRow[0] = true;
    //second base case give true only when arr[index]==target
    prevRow[arr[0]] = true; 

    //write logic in terms of loops
    for(int index=1; index<n; index++){
        vector<bool> currRow(sum+1,false);
        currRow[0] = true;
        for(int target=0; target<=sum; target++){
            bool exclude = prevRow[target];
            bool include = false;
            if(target >= arr[index]){
                include = prevRow[target-arr[index]];
            }
            currRow[target] = include || exclude; 
        }
        prevRow = currRow;
    }
    return prevRow[sum];
}

int main(){
    return 0;
}