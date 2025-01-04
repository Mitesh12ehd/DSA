#include<iostream>
#include<vector>
#include<set>
using namespace std;

//leetcode 827
//Making a larger island

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

int largestIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    //step 1 create components
    DisjointSet ds(m*n);
    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};
    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(grid[row][col] == 0){
                continue;
            }

            int nodeNo = row*n + col;
            for(int i=0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && grid[nrow][ncol] == 1){
                    int adjNodeNo = nrow*n + ncol;
                    ds.UnionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }

    //step 2 try to check every 0
    int ans = 0;
    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(grid[row][col] == 1){
                continue;
            }

            int nodeNo = row*n + col;
            set<int> component;
            for(int i=0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && grid[nrow][ncol] == 1){
                    int adjNodeNo = nrow*n + ncol;
                    component.insert(ds.findParent(adjNodeNo));
                }
            }

            int totalSize = 0;
            for(auto it:component){
                totalSize = totalSize + ds.size[it];
            }
            ans = max(ans,totalSize);
        }
    }

    //handle if there is all 1 in grid
    for(int cell=0; cell<m*n; cell++){
        ans = max(ans,ds.size[ds.findParent(cell)]);
    }
    return ans;
}

int main(){
    return 0;
}