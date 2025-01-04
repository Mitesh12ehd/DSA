#include<iostream>
#include<vector>
using namespace std;

//leetcode 1319
//Number of operation to make network conncected

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

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto it:connections){
        int u = it[0];
        int v = it[1];
        if(ds.findParent(u) == ds.findParent(v)){
            extraEdges++;
        }
        else{
            ds.UnionBySize(u,v);
        }
    }

    int numberOfComponent = 0;
    for(int i=0; i<n; i++){
        if(ds.parent[i] == i){
            numberOfComponent++;
        }
    }

    if(extraEdges >= numberOfComponent-1){
        return numberOfComponent-1;
    }
    else{
        return -1;
    }
}

int main(){
    

    return 0;
}