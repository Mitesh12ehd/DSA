#include<iostream>
#include<vector>
#include<set>
using namespace std;

//gfg
//Articulation point 1

int timer = 1;
void dfs(int node,int parent,vector<int>& visited,int tin[],int low[],set<int>& ans,
vector<int> adj[]){
    visited[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;

    int child = 0; //only used for first source node
    for(auto it:adj[node]){
        if(it == parent){
            continue;
        }
        if(!visited[it]){
            dfs(it,node,visited,tin,low,ans,adj);
            low[node] = min(low[node],low[it]);

            //check for articulation point
            if(tin[node] <= low[it] && parent != -1){
                ans.insert(node);
            }
            child++;
        }
        else{
            low[node] = min(low[node],tin[it]);
        }
    }

    //for source starting node only
    if(parent == -1 && child>1){
        ans.insert(node);
    }
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    vector<int> visited(V,0);
    int tin[V];
    int low[V];
    set<int> ans;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(i,-1,visited,tin,low,ans,adj);
        }
    }
    vector<int> finalAns(ans.begin(),ans.end());
    if(finalAns.size() == 0){
        return {-1};
    }
    return finalAns;
}

int main(){
    return 0;
}