#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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

int spanningTree(int V, vector<vector<int>> adj[]) {
    //O(V+E)
    vector<pair<int,pair<int,int>>> edges;
    for(int node=0; node<V; node++){
        for(auto it:adj[node]){
            int adjNode = it[0];
            int weight = it[1];
            edges.push_back({weight,{node,adjNode}});
        }
    }
    //O(E log E)
    sort(edges.begin(),edges.end());

    //O(E * 4* alpha)
    DisjointSet ds(V);
    int totalWeight = 0;
    for(auto it:edges){
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findParent(u) != ds.findParent(v)){
            totalWeight = totalWeight + weight;
            ds.UnionBySize(u,v);
        }
    }
    return totalWeight;
}

int main(){
    

    return 0;
}