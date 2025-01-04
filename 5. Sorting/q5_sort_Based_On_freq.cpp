#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 1636
static bool myComparator(vector<int> a,vector<int> b){
    if(a[0]<b[0]){
        return true;
    }
    if(a[0] == b[0]){
        if(a[1] > b[1]){
            return true;
        }
        else{
            return false;
        }
    }   
    //if a[0] > b[0]
    return false;
}

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(auto it:nums){
        mp[it]++;
    }

    vector<vector<int>> v;
    for(auto it:mp){
        v.push_back({it.second,it.first});
    }

    sort(v.begin(),v.end(),myComparator);

    vector<int> ans;
    for(auto it:v){
        int freq = it[0];
        int element = it[1];
        while(freq--){
            ans.push_back(element);
        }
    }
    return ans;
}

int main(){
    return 0;
}