#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;

//gfg
//shortest path in undirected weighted graph

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    //create graph from edges
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> parents(n+1);
    for(int i=1; i<=n; i++){
        parents[i] = i;
    }
    pq.push({0,1});
    dist[1] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int distance = it.first;
        pq.pop();
    
        for(auto it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;
    
            if(distance + weight < dist[adjNode]){
                dist[adjNode] = distance + weight;
                parents[adjNode] = node;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    
    if(dist[n] == INT_MAX){
        return {-1};
    }
    vector<int> ans;
    //first element is weight as given in question
    ans.push_back(dist[n]);
    int temp = n;
    while(parents[temp] != temp){
        ans.push_back(temp);
        temp = parents[temp];
    }
    ans.push_back(1);
    reverse(ans.begin()+1,ans.end());
    return ans;
}


int main(){
    return 0;
}