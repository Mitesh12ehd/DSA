#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

//leetcode  743
//network delay time

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:times){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    dist[k] = 0;
    pq.push({0,k});

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode = it.first;
            int weight = it.second;

            if(distance + weight < dist[adjNode]){
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        if(dist[i] == INT_MAX){
            return -1;
        }
        ans = max(ans,dist[i]);
    }
    return ans;
}

int main(){
    return 0;
}