#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//gfg

void dfs(int node,vector<int>& visited,vector<vector<int>>& adj,stack<int>& st){
    visited[node] = 1;
        
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,st);
        }
    }
    st.push(node);
}
// Function to return list containing vertices in Topological order.
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int v = adj.size();
    vector<int> visited(v,0);
    stack<int> st;
    
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }
        
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
  
int main(){
    return 0;
}