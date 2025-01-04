#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//gfg

vector<int> topologicalSort(vector<vector<int>>& adj) {
    // Your code here
    int v = adj.size();
    vector<int> indegree(v,0);
        
    for(int i=0; i<v; i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
        
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
        
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){

    return 0;
}