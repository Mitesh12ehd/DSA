#include<iostream>
#include<vector>
#include<limits.h>
#include<deque>
#include<vector>
using namespace std;

//leetcode 2290
//minimum obstacle removal to reach corner

//to minimize obstacle on path we give priority to obstacle free node i.e 0
//to ensure we get path with 0 node we push it to front of queue
//and path with 1 node push it to back of queue

int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited(m,vector<int>(n,0));
    visited[0][0] = 1;
    deque<pair<pair<int,int>,int>> dq; //<<row,col>,cellRemoved>
    dq.push_front({{0,0},0});
    int ans = INT_MAX;

    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};
    while(!dq.empty()){
        int row = dq.front().first.first;
        int col = dq.front().first.second;
        int cellRemoved = dq.front().second;
        dq.pop_front();

        for(int i=0; i<4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            //check if we reach right bottom node
            if(nrow == m-1 && ncol == n-1){
                ans = min(ans,cellRemoved);
            }

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
            !visited[nrow][ncol]){
                int newCellCount = cellRemoved;
                if(grid[nrow][ncol] == 1){
                    dq.push_back({{nrow,ncol},newCellCount+1});
                }
                else{
                    dq.push_front({{nrow,ncol},newCellCount});
                }
                visited[nrow][ncol] = 1;
            }
        }
    }

    return ans;
}

int main(){
    

    return 0;
}