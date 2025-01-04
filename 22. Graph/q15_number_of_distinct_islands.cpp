#include<iostream>
#include<vector>
#include<set>
using namespace std;

//gfg

void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,
        vector<pair<int,int>>& path,int baseRow,int baseCol){
    
    visited[row][col] = 1;
    path.push_back({row-baseRow , col-baseCol});
    int m = grid.size();
    int n = grid[0].size();
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
        && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow,ncol,visited,grid,path,baseRow,baseCol);
        }
    }

}
int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    set<vector<pair<int,int>>> st;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> path;
                dfs(i,j,visited,grid,path,i,j);
                st.insert(path);
            }
        }
    }
    return st.size();
}


int main(){
    return 0;
}