#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//leetcode 2577
//Minimum time to visit cells in a grid

//we have only one case where we return -1
//when (0,1) and (1,0) have greater value than 1 second

//read explanation on notes

int minimumTime(vector<vector<int>>& grid) {
    if(grid[0][1] > 1+grid[0][0] && grid[1][0] > 1+grid[0][0]){
        return -1;
    }

    int m = grid.size();
    int n = grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> visited(m,vector<int>(n,0));
    pq.push({0,{0,0}});
    visited[0][0] = true;
    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};

    while(!pq.empty()){
        int time = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(row == m-1 && col == n-1){
            return time;
        }

        for(int i=0; i<4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                visited[nrow][ncol] = 1;

                if(grid[nrow][ncol] <= time + 1){
                    pq.push({time+1,{nrow,ncol}});
                }
                else{
                    //we can't make direct jump 
                    //i.e. we have to perform back and forth movement
                    int gap = grid[nrow][ncol] - time;
                    if(gap % 2 == 0){
                        //if gap is even
                        int new_time = time + gap + 1;
                        pq.push({new_time,{nrow,ncol}});
                    }
                    else{
                        //if gap is odd
                        int new_time = time + gap;
                        pq.push({new_time,{nrow,ncol}});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}