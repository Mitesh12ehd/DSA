#include<iostream>
#include<vector>
using namespace std;

//gfg
bool detect(int node,int parent,vector<vector<int>>& adj,int visited[]){
    visited[node] = 1;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            if(detect(neighbour,node,adj,visited)){
                return true;
            }
        }
        else if(visited[neighbour] && parent != neighbour){
            return true;
        }
    }
    return false;
}
bool isCycle(vector<vector<int>>& adj) {
    int v = adj.size();
    int visited[v] = {0};
    for(int i=0; i<v; i++){
        if(!visited[i]){
            if(detect(i,-1,adj,visited)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    return 0;
}