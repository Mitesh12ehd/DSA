#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//gfg

bool detect(int src,vector<vector<int>>& adj,int visited[]){
    visited[src] = true;
    queue<pair<int,int>> q;
    q.push({src,-1});
        
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
            
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                q.push({neighbour,node});
            }
            else if(visited[neighbour] && parent != neighbour){
                return true;
            }
        }
    }
    return false;
}
    
bool isCycle(vector<vector<int>>& adj) {
    int v = adj.size();
    int visited[v] = {0};
    for(int i=0; i<v; i++){
        if(!visited[i]){
            if(detect(i,adj,visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    return 0;
}