#include<iostream>
#include<vector>
using namespace std;

//leetcode 2685
//count the number of complete component

//for a completely connected graph
//n = number of nodes
//total edges = n*(n-1) / 2

void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,int& countEdges,int& countNodes){
    visited[node] = 1;

    for(auto it:adj[node]){
        countEdges++;
        if(!visited[it]){
            countNodes++;
            dfs(it,adj,visited,countEdges,countNodes);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
        
    int ans = 0;
    vector<int> visited(n,0);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int countEdges = 0;
            int countNodes = 1;
            dfs(i,adj,visited,countEdges,countNodes);

            //check
            countEdges = countEdges / 2;
            int validCount = (countNodes * (countNodes - 1)) / 2;
            if(validCount == countEdges){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}