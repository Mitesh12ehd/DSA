#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

//leetcode 787
//cheapest flight within k stops

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:flights){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
    }
    //{stops,{node,dist}}
    queue<pair<int,pair<int,int>>> q;
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    q.push({0,{src,0}});

    while(!q.empty()){
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(stops > k){
            continue;
        }

        for(auto it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;

            if(weight + cost < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + weight;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }
        }
    }  
    if(dist[dst] == INT_MAX){
        return -1;
    } 
    return dist[dst];
}

int main(){
    return 0;
}