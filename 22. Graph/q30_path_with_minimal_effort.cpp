#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

//leetcode 1631
//path with minimal effort

//brute force time = (4 ^ m*n)
void helper(vector<vector<int>>& heights,int row,int col,vector<vector<int>> visited,int& maxDiff,int& ans){
    if(row == heights.size()-1 && col == heights[0].size()-1){
        ans = min(ans,maxDiff);
        return;
    }

    //visit 4 direction
    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};
    for(int i=0; i<4; i++){
        int nrow = row + dRow[i];
        int ncol = col + dCol[i];

        if(nrow>=0 && nrow<heights.size() && ncol>=0 && ncol<heights[0].size()
        && !visited[nrow][ncol]){
            int diff = abs(heights[nrow][ncol] - heights[row][col]);
            int temp = maxDiff;
            maxDiff = max(maxDiff,diff);
            visited[nrow][ncol] = 1;
            helper(heights,nrow,ncol,visited,maxDiff,ans);
            visited[nrow][ncol] = 0;
            maxDiff = temp;
        }
    }
    
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int ans = INT_MAX;
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    int maxDiff = INT_MIN;
    visited[0][0] = 1;
    helper(heights,0,0,visited,maxDiff,ans);

    if(ans == INT_MIN || ans == INT_MAX){
        return 0;
    }
    return ans;
}

//using dijkastra
int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    dist[0][0] = 0;
    pq.push({0,{0,0}});

    int dRow[] = {-1,0,1,0};
    int dCol[] = {0,1,0,-1};
    while(!pq.empty()){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int difference = pq.top().first;
        pq.pop();

        if(row==m-1 && col==n-1){
            return difference;
        }

        for(int i=0; i<4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                int newEffort = max(difference,abs(heights[nrow][ncol] - heights[row][col]));
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}

int main(){
    return 0;
}