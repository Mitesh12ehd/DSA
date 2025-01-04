#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 547

void bfs(vector<int> adjList[],vector<bool>& visited,queue<int>& q){
    while(!q.empty()){
        int node = q.front();
        q.pop();
    
        //push all it's neighbour into queue
        for(auto it:adjList[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<int> adjList[V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(isConnected[i][j] == 1 && i!=j){
                adjList[i].push_back(j);
            }
        }
    }
        
        
    // Code here
    int count = 0;
    vector<bool> visited(V,false);
    queue<int> q;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            count++;
            q.push(i);
            visited[i] = true;
            bfs(adjList,visited,q);
        }
    }
    return count;
}

int main(){
    return 0;
}