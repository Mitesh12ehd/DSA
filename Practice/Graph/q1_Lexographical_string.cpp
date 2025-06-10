#include<iostream>
#include<vector>
using namespace std;

// Leetcode 1061
// Lexicographically Smallest Equivalent String

class DisjointSet{
    public:

    vector<int> parent;

    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionChar(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        //if they are already belonged to same component
        if(ulp_u == ulp_v){
            return;
        }

        if(ulp_u > ulp_v){
            parent[ulp_u] = ulp_v;
        }
        else if(ulp_u < ulp_v){
            parent[ulp_v] = ulp_u;
        }
        else{
            //if rank is equal
            parent[ulp_v] = ulp_u;
        }
    }
};

string smallestEquivalentString(string s1, string s2, string baseStr) {
    DisjointSet ds(26);

    for(int i=0; i<s1.length(); i++){
        int u = s1[i] - 'a';
        int v = s2[i] - 'a';
        ds.unionChar(u,v);
    }

    for(int i=0; i<baseStr.length(); i++){
        baseStr[i] = ds.findParent(baseStr[i] - 'a') + 'a';
    }
    return baseStr;
}

int main(){
    return 0;
}