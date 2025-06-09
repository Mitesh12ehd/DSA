#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//GFG
//Partition with given difference

/* 
    Observation:
        sum1 - sum2 = diff
        (total - sum2) - sum2 = diff
        total - 2sum2 = diff
        sum2 = (diff - total)/2

    so we need to count subset that form sum = sum2

    Edge cases :
        1. (total - diff) should be positive
        2. (total - diff) should be even

    Note : here we can also replace value of sum2 = total - sum1 in equation
    then we need to count subset with sum1 = (diff + total) / 2,
    both approach give same answer
*/

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
int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int totalSum = 0;
    for(auto it:arr){
        totalSum += it;
    }

    if(totalSum - d < 0){
        return 0;
    }
    if((totalSum-d) % 2 == 1){
        return 0;
    }
    int sum2 = (totalSum - d) / 2;
    return perfectSum(arr,sum2);
}

int main(){
    return 0;
}