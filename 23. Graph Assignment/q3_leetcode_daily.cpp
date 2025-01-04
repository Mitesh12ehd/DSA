#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 3243
//shortest distnace after road addition queries I

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        adj[i].push_back(i+1);
    }

    vector<int> ans;
    for(auto it:queries){
        adj[it[0]].push_back(it[1]);
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> visited(n,0);
        visited[0] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(node == n-1){
                ans.push_back(steps);
                break;
            }

            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push({it,steps+1});
                    visited[it] = 1;
                }
            }
        }
    }
    return ans;
}

int main(){
    

    return 0;
}