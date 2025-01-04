#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//leetcode 1976
//Number of ways to arrive at destination

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:roads){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX);
    vector<int> ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});

    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;
                
            if(weight + distance < dist[adjNode]){
                //if we got new minimum distance
                dist[adjNode] = weight + distance;
                pq.push({dist[adjNode],adjNode});
                ways[adjNode] = ways[node];
            }
            else if(weight + distance == dist[adjNode]){
                //if we got new ways to reach adjnode with same shortest distance
                ways[adjNode] = ways[adjNode] + ways[node];
            }
        }
    }
    return ways[n-1];
}

int main(){
    return 0;
}