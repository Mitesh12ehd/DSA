#include<iostream>
#include<vector>
using namespace std;

//gfg
//Number of islands

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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n*m);
    vector<vector<int>> visited(n,vector<int>(m,0));
    int count = 0;
    vector<int> ans;
    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};

    for(auto it:operators){
        int row = it[0];
        int col = it[1];

        if(visited[row][col] == 1){
            ans.push_back(count);
            continue;
        }

        visited[row][col] = 1;
        count++;
        for(int i=0; i<4; i++){
            int adjRow = row + dRow[i];
            int adjCol = col + dCol[i];

            if(adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m
            && visited[adjRow][adjCol] == 1){
                int nodeNo = row*m + col;
                int adjNodeNo = adjRow*m + adjCol;
                if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo)){
                    count--;
                    ds.UnionBySize(nodeNo,adjNodeNo); 
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    return 0;
}