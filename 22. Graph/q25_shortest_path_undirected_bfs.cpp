#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

//gfg
//shortest path in undirected graph with unit weight

vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
    vector<vector<int>> adj(n);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
        
    vector<int> dis(n,INT_MAX);
    queue<pair<int,int>> q; //<element,distance>
                            //distace to reach src node to element node
    q.push({src,0});
    dis[src] = 0;
    
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        
        for(auto it:adj[node]){
            int prevDis = dis[it];
            int newDis = distance + 1;
            
            if(newDis < prevDis){
                dis[it] = newDis;
                q.push({it,newDis});
            }
        }
    }
        
    //mark unreacble node as -1
    for(int i=0; i<n; i++){
        if(dis[i] == INT_MAX){
            dis[i] = -1;
        }
    }
    return dis;
}


int main(){
    return 0;
}