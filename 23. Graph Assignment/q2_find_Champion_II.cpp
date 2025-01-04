#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode 2924
//find champion II

//intitution : we have find a node who have indegree == 0
//if there is multiple node with indegree==0  or zero node with indegree==0 , then return -1

int findChampion(int n, vector<vector<int>>& edges) {
    unordered_map<int,int> mp;

    for(auto it:edges){
        mp[it[1]]++;
    }

    for(auto it:mp){
        cout << it.first << " -> " << it.second;
            cout << endl;
    }

    int champion = -1;
    for(int i=0; i<n; i++){
        if(mp.find(i) == mp.end() && champion == -1){
            champion = i;
        }
        else if(mp.find(i) == mp.end() && champion != -1){
            return -1;
        }
    }

    return champion;
}

int main(){
    return 0;
}