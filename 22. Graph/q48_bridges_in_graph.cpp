#include<iostream>
#include<vector>
using namespace std;

//leetcode 1192
//Critical connection in a network

int timer = 1;
void dfs(int node,int parent,vector<int>& visited,int tin[],int low[],
    vector<vector<int>>& adj,vector<vector<int>>& bridges){
    
    visited[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;

    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }

        if(visited[it] == 0){
            dfs(it,node,visited,tin,low,adj,bridges);
            low[node] = min(low[node],low[it]);

            //now check if node to it is a bridge?
            if(tin[node] < low[it]){
                //there is a bridge
                bridges.push_back({it,node});
            }
        }
        else{
            low[node] = min(low[node],low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    //create graph
    vector<vector<int>> adj(n);
    for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> visited(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0,-1,visited,tin,low,adj,bridges);
    return bridges;
}

int main(){
    return 0;
}