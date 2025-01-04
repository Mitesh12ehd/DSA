#include<iostream>
#include<vector>
#include<set>
using namespace std;

//leetcode 947
//Most stone removed with same row or column

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

int removeStones(vector<vector<int>>& stones) {
    int totalStone = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for(auto it:stones){
        maxRow = max(maxRow,it[0]);
        maxCol = max(maxCol,it[1]);
    }

    DisjointSet ds(maxRow+maxCol+1);
    set<int> st; //set to keep track of row and col who have stones
    for(auto it:stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.UnionBySize(nodeRow,nodeCol);
        st.insert(nodeRow);
        st.insert(nodeCol);
    } 

    int totalComponent = 0;
    for(auto it:st){
        if(ds.findParent(it) == it){
            totalComponent++;
        }
    }

    return totalStone - totalComponent;
}

int main(){
    return 0;
}