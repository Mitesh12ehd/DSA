#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//DFS method
// bool dfs(int node,vector<vector<int>>& graph,vector<int>& color,int col){
//     color[node] = col;

//     for(auto it:graph[node]){
//         if(color[it] == -1){
//             //neighbour is not visited and not coloured
//             if(!dfs(it,graph,color,!col)){
//                 return false;
//             }
//         }
//         else{
//             // neighbour isvisited and coloured
//             if(color[it] == col){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool isBipartite(vector<vector<int>>& graph) {
//     int v = graph.size();
//     vector<int> color(v,-1);

//     for(int i=0; i<v; i++){
//         if(color[i] == -1){
//             if(!dfs(i,graph,color,0)){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

//BFS method
bool helper(int src,vector<vector<int>>& graph,vector<int>& color){
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:graph[node]){
            if(color[it] == -1){
                //neighbour not coloured
                q.push(it);
                color[it] = !color[node];
            }
            else{
                //neighbour is already visited and colored
                if(color[node] == color[it]){
                    return false;
                }
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> color(v,-1);
    for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(!helper(i,graph,color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    

    return 0;
}