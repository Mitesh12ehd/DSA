#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solveProblem(vector<int> arr,int i,int sum,int &maximum_sum){
    if( i>= arr.size()){
        maximum_sum = max(maximum_sum , sum);
        return;
    }

    //include
    solveProblem(arr, i+2, sum+arr[i], maximum_sum);
    //exclude
    solveProblem(arr, i+1, sum, maximum_sum);
}

//backtrack method
// void helper(vector<int>& arr,int i,int& sum,int& maxSum){
//     if(i >= arr.size()){
//         maxSum = max(sum,maxSum);
//         return;
//     }

//     //include
//     sum = sum + arr[i];
//     helper(arr,i+2,sum,maxSum);
//     sum = sum - arr[i];

//     //exclude
//     helper(arr,i+1,sum,maxSum);
// }


int main(){
    vector<int> arr{2,1,4,9};
    int sum = 0;
    int maximum_sum = INT_MIN;
    int i=0;
    solveProblem(arr,i,sum,maximum_sum);
    cout << maximum_sum;

    return 0;
}