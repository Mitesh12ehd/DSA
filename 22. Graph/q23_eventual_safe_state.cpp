#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//leetcode 802
//find eventual safe states


//using dfs
// bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVis,vector<int>& check){
//     visited[node] = 1;
//     pathVis[node] = 1;
        
//     for(auto it:adj[node]){
//         if(!visited[it]){
//             if(dfs(it,adj,visited,pathVis,check)){
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         else if(visited[it] && pathVis[it]){
//             check[node] = 0;
//             return true;
//         }
//     }
//     check[node] = 1; //mark as safe node, because if there is cycle it returns earlier
//     pathVis[node] = 0;
//     return false;
// }
// vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//     int V = graph.size();
//     vector<int> visited(V,0);
//     vector<int> pathVis(V,0);
//     vector<int> check(V,0);
        
//     for(int i=0; i<V; i++){
//         if(!visited[i]){
//             dfs(i,graph,visited,pathVis,check);
//         }
//     }

//     vector<int> safeNodes;
//     for(int i=0; i<V; i++){
//         if(check[i] == 1){
//             safeNodes.push_back(i);
//         }
//     }
//     return safeNodes;
// }


//using bfs topo sort concept
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();

    //reverse the all edge of graph
    vector<vector<int>> adjRev(v);
    for(int i=0; i<v; i++){
        for(auto it:graph[i]){
            adjRev[it].push_back(i);
        }
    }

    //count indegree
    vector<int> indegree(v,0);
    for(int i=0; i<v; i++){
        for(auto it:adjRev[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> safenodes;
    //push all node who have indegree=0
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safenodes.push_back(node);

        //visit neighbour
        for(auto it:adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    sort(safenodes.begin(),safenodes.end());
    return safenodes;
}

int main(){
    return 0;
}