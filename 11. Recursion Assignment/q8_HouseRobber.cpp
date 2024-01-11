#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solveProblem(vector<int>&nums,int i,int sum,int& maximum_sum){
    //base case
    if( i>= nums.size()){
        maximum_sum = max(maximum_sum , sum);
        return;
    }
    //include
    solveProblem(nums, i+2, sum + nums[i] , maximum_sum);
    //exclude
    solveProblem(nums, i+1, sum, maximum_sum);
}
int rob(vector<int>& nums) {
    int sum = 0;
    int maximum_sum = INT_MIN;
    int i = 0;

    solveProblem(nums,i,sum,maximum_sum);
    return maximum_sum;
}
int main(){
    //same as "sum of non adjacent element"
    vector<int> nums{1,2,3,1};
    cout << rob(nums);
    return 0;
}