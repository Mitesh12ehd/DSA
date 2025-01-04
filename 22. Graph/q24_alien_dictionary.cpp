#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//gfg

string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];
    
    //create graph
    for(int i=0; i<n-1; i++){
        //compare i and i+1 word
        int index = 0;
        string s1 = dict[i];
        string s2 = dict[i+1];
        int n1 = s1.length();
        int n2 = s2.length();
        
        while(index < n1 && index < n2){
            if(s1[index] != s2[index]){
                int ch1 = s1[index]; //appear first
                int ch2 = s2[index]; //appera letter
                
                //make edge from ch1 and ch2
                adj[ch1-'a'].push_back(ch2-'a');
                break;
            }
            index++;
        }
    }
    
    //apply topo sort
    int v = k;
    vector<int> indegree(v,0);
        
    for(int i=0; i<v; i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
        
    string ans;
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
        
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node+'a');
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