#include<iostream>
#include<vector>
using namespace std;

//this question use similiar approach to find missing element question
//note : whenever element of array lies into [1,N] 
//         this approach may use by triet element as index

int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0){
            return abs(nums[i]);
        }
        else{
            nums[index] = nums[index] * (-1);
        }
    }

    return -1;
}

int main(){
    return 0;
}