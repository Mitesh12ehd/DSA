#include<iostream>
#include<vector>
using namespace std;

//Leetcode 136
//Single number

//brute force can be store freq in hash table and 
//      return which number has freq=1

//optimal approach
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(auto it:nums){
        ans = ans ^ it;
    }
    return ans;
}

int main(){
    return 0;
}