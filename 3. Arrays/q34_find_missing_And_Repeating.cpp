#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 2965
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int,int> mp;
    int n = grid.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mp[grid[i][j]]++;
        }
    }

    int repeated,missing;
    for(int i=1; i<=n*n; i++){
        if(mp.find(i) == mp.end()){
            missing = i;
            continue;
        }

        if(mp[i] == 2){
            repeated = i;
        }
    }

    vector<int> ans;
    ans.push_back(repeated);
    ans.push_back(missing);
    return ans;
}

int main(){
    

    return 0;
}