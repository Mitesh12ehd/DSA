#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 778
//swim in rising water

//Dijkstra time = O(n^2 log n)
int swimInWater(vector<vector<int>>& grid) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    int maxTime = 0;
    int n = grid.size();
    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};
    vector<vector<int>> visited(n,vector<int>(n,0));
    visited[0][0] = 1;

    while(!pq.empty()){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int time = pq.top().first;
        pq.pop();
        maxTime = max(maxTime,grid[row][col]);

        if(row == n-1 && col == n-1){
            return maxTime;
        } 

        for(int i=0; i<4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
            && !visited[nrow][ncol]){
                pq.push({grid[nrow][ncol],{nrow,ncol}});
                visited[row][col] = 1;
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}