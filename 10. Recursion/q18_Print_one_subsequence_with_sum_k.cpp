#include<iostream>
#include<vector>
using namespace std;

//Print One the subseqeuence with sum k

// time = O(2 ^ n)
// 2 call per call
// depth of tree = n

//when array is distinict : number of subsequence generate is 2^n
//subsequence doesn't contain same element twice.

bool helper(int i,vector<int>& nums,int sum,int target,vector<int>& v){
    if(i == nums.size()){
        if(sum == target){
            //print subsequence
            for(auto it:v){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    //include
    v.push_back(nums[i]);
    if(helper(i+1,nums,sum+nums[i],target,v)){
        return true;
    }
    v.pop_back();

    //exclude ith element of array
    if(helper(i+1,nums,sum,target,v)){
        return true;
    }

    return false; 
}
void printAllSubSequenceWithSumk(vector<int>& nums, int target) {
    int ans = 0;
    int sum = 0;
    int i = 0;
    vector<int> v;
    helper(i,nums,sum,target,v);
}

int main(){
    vector<int> nums = {1,2,1};
    int sum = 2;
    printAllSubSequenceWithSumk(nums,sum);
    return 0;
}