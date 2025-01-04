#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//gfg
//Minimum Spanning Tree

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(V,0);
    pq.push({0,0});
    int sum = 0;
        
    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
            
        if(visited[node]){
            continue;
        }
            
        visited[node] = 1;
        sum = sum + weight;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int adjWeight = it[1];
            if(!visited[adjNode]){
                pq.push({adjWeight,adjNode});
            }
        }
    }
    return sum;
}

int main(){
    return 0;
}