#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Naukri
// Array partition with minimum difference

//see notes

//tabulation
//time = O(n*totalSum)
//space = O(n*totalSum)
int minSubsetSumDifference(vector<int>& arr, int n){
    int totalSum = 0;
    for(auto it:arr){
        totalSum += it;
    }

    //fill the table
    vector<vector<bool>> dp(n,vector<bool>(totalSum+1,false));
    //base case
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    //second base case give true only when arr[index]==target
    dp[0][arr[0]] = 1; 
    //write logic in terms of loops
    for(int index=1; index<n; index++){
        for(int target=0; target<=totalSum; target++){
            bool exclude = dp[index-1][target];
            bool include = false;
            if(target >= arr[index]){
                include = dp[index-1][target-arr[index]];
            }
            dp[index][target] = include || exclude; 
        }
    }

    int minimumDifference = INT_MAX;
    //iterate last row
    for(int target=0; target<=totalSum; target++){
        if(dp[n-1][target] == true){
            int sum1 = target;
            int sum2 = totalSum - sum1;
            int absDiff = abs(sum1 - sum2);
            minimumDifference = min(minimumDifference,absDiff);
        }
    }
    return minimumDifference;
}

//space optimization
//time = O(n*totalSum)
//space = O(totalSum)
int minSubsetSumDifference(vector<int>& arr, int n){
    int totalSum = 0;
    for(auto it:arr){
        totalSum += it;
    }

    //fill the table
    vector<bool> prevRow(totalSum+1,false);
    //base case
    prevRow[0] = true;
    //second base case give true only when arr[index]==target
    prevRow[arr[0]] = true; 

    //write logic in terms of loops
    for(int index=1; index<n; index++){
        vector<bool> currRow(totalSum+1,false);
        currRow[0] = true;
        for(int target=0; target<=totalSum; target++){
            bool exclude = prevRow[target];
            bool include = false;
            if(target >= arr[index]){
                include = prevRow[target-arr[index]];
            }
            currRow[target] = include || exclude; 
        }
        prevRow = currRow;
    }

    int minimumDifference = INT_MAX;
    //iterate last row
    for(int target=0; target<=totalSum; target++){
        if(prevRow[target] == true){
            int sum1 = target;
            int sum2 = totalSum - sum1;
            int absDiff = abs(sum1 - sum2);
            minimumDifference = min(minimumDifference,absDiff);
        }
    }
    return minimumDifference;
}

int main(){
    return 0;
}