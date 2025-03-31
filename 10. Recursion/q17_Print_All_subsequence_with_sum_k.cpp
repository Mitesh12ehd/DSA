#include<iostream>
#include<vector>
using namespace std;

//Print all the subseqeuence with sum k

//another question
//count all teh subsequence with sum k
//approach will be same just maintain count 
//second approach can be return int from helper
//return ans1 + ans2

//when array is distinict : number of subsequence generate is 2^n
//subsequence doesn't contain same element twice.
//reason : there is 2^n subsets of any set
//if interviewr ask why thenn take example any explain :)

// time = O(2 ^ n)
// 2 call per call
// depth of tree = n
void helper(int i,vector<int>& nums,int sum,int target,vector<int>& v){
    if(i == nums.size()){
        if(sum == target){
            //print subsequence
            for(auto it:v){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    //include
    v.push_back(nums[i]);
    helper(i+1,nums,sum+nums[i],target,v);
    v.pop_back();

    //exclude ith element of array
    helper(i+1,nums,sum,target,v);
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