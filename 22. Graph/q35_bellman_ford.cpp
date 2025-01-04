#include<iostream>
#include<vector>
using namespace std;

//gfg
//bellman ford

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dist(V,100000000);
    dist[src] = 0;
        
    for(int i=0; i<V-1; i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];

            if(dist[u] != 100000000 && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
        
    //nth relaxation to detect nagative cycle
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
                
        if(dist[u] != 100000000 && dist[u] + weight < dist[v]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    return 0;
}