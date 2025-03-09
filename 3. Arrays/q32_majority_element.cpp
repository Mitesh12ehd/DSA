#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

//naive
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count > (n/2)){
            return nums[i];
        }
    }
    return -1;
}

//extra space
int majorityElement(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int> mp;
    for(auto it:nums){
        mp[it]++;
    }

    for(auto it:mp){
        if(it.second > (n/2)){
            return it.first;
        } 
    }
    return -1;
}

//Moore voting algorothim
int majorityElement(vector<int>& nums) {
    int count = 0;
    int currAns = 0;

    for(auto it:nums){
        if(count == 0){
            currAns = it;
        }

        if(it == currAns){
            count++;
        }
        else{
            count--;
        }
    }

    return currAns;
}

int main(){
    

    return 0;
}