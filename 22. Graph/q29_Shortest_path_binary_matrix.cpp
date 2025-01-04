#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//leetcode 1091
//Shortest path in binary matrix

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0] == 1){
        return -1;
    }

    int n = grid.size();
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    dist[0][0] = 1;

    int dRow[] = {-1,0,1,0,-1,-1,1,1};
    int dCol[] = {0,1,0,-1,-1,1,1,-1};
    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int distance = q.front().first;
        q.pop();

        if(row == n-1 && col == n-1){
            return distance;
        }

        //visit 8 direction
        for(int i=0; i<8; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
            && grid[nrow][ncol] == 0 && distance+1 < dist[nrow][ncol]){
                dist[nrow][ncol] = distance + 1;
                q.push({distance+1,{nrow,ncol}});
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}