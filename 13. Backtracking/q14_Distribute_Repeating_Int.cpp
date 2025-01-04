#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool canDistributeHelper(vector<int>& counts, vector<int>& quantity,int ithCustomer){
    //base case
    if(ithCustomer == quantity.size()){
        return true;
    }

    for(int i=0; i<counts.size(); i++){
        if(counts[i] >= quantity[ithCustomer]){
            counts[i] = counts[i] - quantity[ithCustomer];
            if(canDistributeHelper(counts,quantity,ithCustomer+1)){
                return true;
            }
            //backtrack
            counts[i] = counts[i] + quantity[ithCustomer];
        }
    }
    return false;
}
bool canDistribute(vector<int>& nums, vector<int>& quantity){
    //1. we create counts array {2,4,2} because element of nums+_array doesn't matter
    //we need frequency of them only.
    unordered_map<int,int> countMap;
    for(auto num:nums){
        countMap[num]++;
    }
    vector<int> counts;
    for(auto it:countMap){
        counts.push_back(it.second);
    }

    //sort quanity in descending order to avoid TLE
    //reason: we derive false condition fast,
    //largest quatity required customer assign first
    sort(quantity.rbegin(),quantity.rend());

    //recursion
    return canDistributeHelper(counts,quantity,0); //0th customer
}
int main(){
    vector<int> nums{1,1,2,2,2,2,3,3};
    vector<int> quantity{2,2,3};
    cout << canDistribute(nums,quantity);
    return 0;
}