#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int,int> mp;

    for(auto it:nums){
        mp[it]++;
    }
        
    int ans;
    int maxFreq = INT_MIN;
    for(auto it:mp){
        if(it.second > maxFreq){
            ans = it.first;
            maxFreq = it.second;
        } 
    }

    return ans;
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