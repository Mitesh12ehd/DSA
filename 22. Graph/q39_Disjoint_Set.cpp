#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:

    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        rank.resize(n+1,0); 
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

    void UnionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        //if they are already belonged to same component
        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            //if rank is equal
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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

int main(){
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);

    //check if 3 and 7 belong to same component
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "3 and 7 belong to same componenet"  << endl;
    }
    else{
        cout << "3 and 7 not belong to same component" << endl;
    }

    ds.UnionByRank(3,7);

    //check if 3 and 7 belong to same component
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "3 and 7 belong to same componenet"  << endl;
    }
    else{
        cout << "3 and 7 not belong to same component" << endl;
    }

    return 0;
}