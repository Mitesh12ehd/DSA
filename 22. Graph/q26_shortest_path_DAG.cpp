#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

//gfg
//shortest path in directed avyclic graph

void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int>& visited,stack<int>& st){
    visited[node] = 1;
    for(auto it:adj[node]){
        int v = it.first;
        if(!visited[v]){
            dfs(v,adj,visited,st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
    }
        
    //store topological order
    vector<int> visited(V,0);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
        
    //now perform algorithm
    vector<int> dist(V,INT_MAX);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
            
        for(auto it:adj[node]){
            int v = it.first;
            int weight = it.second;
                
            if(dist[node] != INT_MAX && dist[node] + weight < dist[v]){
                dist[v] = dist[node] + weight;
            }
        }
    }
    
    for(int i=0; i<V; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
}

int main(){
    return 0;
}