#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//leetcode 721
//Accounts merge

class DisjointSet{
    public:

    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void UnionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        //if they are already belonged to same component
        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v] + size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v] + size[ulp_u];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    unordered_map<string,int> mp;
    DisjointSet ds(n);

    for(int i=0; i<n; i++){
        for(int j=1; j<accounts[i].size(); j++){
            string email = accounts[i][j];
            if(mp.find(email) == mp.end()){
                mp[email] = i;
            }
            else{
                ds.UnionBySize(mp[email],i);
            }
        }
    }

    vector<vector<string>> mergeMail(n);
    for(auto it:mp){
        string email = it.first;
        int node = ds.findParent(it.second);
        mergeMail[node].push_back(email);
    }

    vector<vector<string>> ans;
    for(int i=0; i<n; i++){
        if(mergeMail[i].size() == 0){
            continue;
        }
        sort(mergeMail[i].begin(),mergeMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it:mergeMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    return 0;
}