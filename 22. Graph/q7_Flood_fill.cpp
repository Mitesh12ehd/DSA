#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//leetcode 733  

//bfs method
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int intital_color = image[sr][sc];

    vector<vector<int>> visited(m,vector<int>(n,0));
    visited[sr][sc] = 1;
    image[sr][sc] = color;
    queue<pair<int,int>> q;
    q.push({sr,sc});

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
            
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
            && visited[nrow][ncol]==0
            && image[nrow][ncol] != color 
            && image[nrow][ncol] == intital_color){
                q.push({nrow,ncol});
                visited[nrow][ncol] = 1;
                image[nrow][ncol] = color;
            }
        }
    }
        
    return image;
}

//dfs method
void dfs(int row,int col,vector<vector<int>>& image,int new_color,int intial_color,int delRow[],int delCol[]){
    image[row][col] = new_color;
    int m = image.size();
    int n = image[0].size();
    for(int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
        && image[nrow][ncol] == intial_color
        && image[nrow][ncol] != new_color){
            dfs(nrow,ncol,image,new_color,intial_color,delRow,delCol);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int intial_color = image[sr][sc];
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    dfs(sr,sc,image,color,intial_color,delRow,delCol);
    return image;
}

int main(){
    return 0;
}