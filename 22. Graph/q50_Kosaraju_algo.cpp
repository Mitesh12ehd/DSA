#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//gfg
//strongly connected

void dfs(int node,vector<int>& visited,vector<vector<int>> &adj,stack<int>& st){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,st);
        }
    }
    st.push(node);
}

void dfs3(int node,vector<int>& visited3,vector<vector<int>>& adjr){
    visited3[node] = 1;
    for(auto it:adjr[node]){
        if(!visited3[it]){
            dfs3(it,visited3,adjr);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();

    //step 1
    vector<int> visited(n,0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }

    //step 2
    vector<vector<int>> adjr(n);
    for(int i=0; i<n; i++){
        for(auto it:adj[i]){
            adjr[it].push_back(i);
        }
    }

    //step 3
    int ans = 0;
    vector<int> visited3(n,0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited3[node]){
            ans++;
            dfs3(node,visited3,adjr);
        }
    }
    return ans;
}

int main(){
    return 0;
}