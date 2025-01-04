#include<iostream>
#include<vector>
using namespace std;

//leetcode 547
//Number of Provinces

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

int findCircleNum(vector<vector<int>>& isConnected) {
    int v = isConnected.size();
    DisjointSet ds(v);

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(isConnected[i][j] == 1){
                ds.UnionBySize(i,j);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<v; i++){
        if(ds.parent[i] == i){
            ans++;
        }
    }
    return ans;
}


int main(){
    return 0;
}