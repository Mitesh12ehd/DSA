#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 994

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
        
    // queue<{{row,col},time}>
    queue <pair<pair<int,int>,int>> q;
    int visited[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            else{
                visited[i][j] = 0;
            }
        }
    }

    int tmax = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tmax = max(tmax,t);
        q.pop();
            
        //rotting neighbour oranges
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m
            && visited[nrow][ncol]== 0 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1});
                visited[nrow][ncol] = 2;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && visited[i][j] != 2){
                return -1;
            }
        }
    }

    return tmax;
}

int main(){
    return 0;
}