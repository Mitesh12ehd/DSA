#include<iostream>
#include<vector>
using namespace std;

//gfg    
bool dfs(int node,vector<vector<int>>& adj,int visited[],int pathVis[]){
    visited[node] = 1;
    pathVis[node] = 1;
        
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,adj,visited,pathVis)){
                return true;
            }
        }
        else if(visited[it] && pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<vector<int>> adj) {
    int visited[V] = {0};
    int pathVis[V] = {0};
        
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,pathVis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    return 0;
}