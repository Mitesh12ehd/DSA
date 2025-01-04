#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 207 
//course schedule

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
	for(auto it:prerequisites){
	    adj[it[1]].push_back(it[0]);
	}
	    
	//code for detecting cycle using bfs(topo sort)
	int v = numCourses;
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
            
    if(ans.size() == v){
        return true;
    }
    return false;
}

int main(){
    return 0;
}