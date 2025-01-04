#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//leetcode 542
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<vector<int>> ans(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>> q; //{{row,col},distance}

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        ans[row][col] = distance;

        for(int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
            && !visited[nrow][ncol]){
                visited[nrow][ncol] = 1;
                q.push({{nrow,ncol},distance+1}); 
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}