#include<iostream>
#include<vector>
using namespace std;

//gfg
void dfs(int src,bool visited[],vector<vector<int>>& adj,vector<int>& ans){
    ans.push_back(src);
    visited[src] = true;
    for(auto it:adj[src]){
        if(!visited[it]){
            dfs(it,visited,adj,ans);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    int n = adj.size();
    bool visited[n] = {false};
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,visited,adj,ans);
        }
    }
    return ans;
}

int main(){
    return 0;
}