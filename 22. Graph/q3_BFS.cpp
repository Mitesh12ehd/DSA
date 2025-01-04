#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &adj,bool visited[],queue<int>& q,vector<int>& ans){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        //push all it's neighbour into queue
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

//gfg
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    // Code here
    int n = adj.size();
    bool visited[n] = {false};
    queue<int> q;
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            bfs(adj,visited,q,ans);
        }
    }
    return ans;
}

int main(){
    return 0;
}