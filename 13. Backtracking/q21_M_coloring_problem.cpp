#include<iostream>
#include<vector>
using namespace std;

//GFG
//M coloring problem

// time = O(n^m) 
// there are m call per 1 call 
// depth of tree is n

// space = O(n+n)

bool isSafe(int node,vector<int>& colored,vector<vector<int>>& adj,int i){
    for(auto neighbour:adj[node]){
        if(i == colored[neighbour]){
            return false;
        }
    }
    return true;    
}
bool helper(vector<vector<int>>& adj,vector<int>& colored,int node,int m){
    if(node == adj.size()){
        return true;
    }

    for(int i=1; i<=m; i++){
        if(isSafe(node,colored,adj,i)){
            colored[node] = i;
            if(helper(adj,colored,node+1,m)){
                return true;
            }
            colored[node] = 0;
        }
    }
    return false;
}
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    vector<vector<int>> adj(v);
    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int> colored(v,0);
    return helper(adj,colored,0,m);
}

int main(){
    return 0;
}