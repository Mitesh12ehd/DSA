#include<iostream>
#include<vector>
using namespace std;

//array have n/2 positive and n/2 nagative elements
//n is strictly even

//arr = [3,1,-2,-5,2,-4]
//order of positive number is must be maintained
//order of nagative number is must be maintained
//ans = [3,-2,1,-5,2,-4]

vector<int> rearrangeArray(vector<int>& nums) {
    int n  = nums.size();
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<n || j<n){
        while(i<n && nums[i] < 0){
            i++;
        }
        if(i<n){
            ans.push_back(nums[i]);
        }
        i++;

        while(j<n && nums[j] > 0){
            j++;
        }
        if(j<n){
            ans.push_back(nums[j]);
        }
        j++;
    }
    return ans;
}

int main(){
    return 0;
}