#include<iostream>
#include<vector>
using namespace std;

//leetcode 130

void dfs(int row,int col,vector<vector<char>>& board,
    vector<vector<int>>& visited,
    int delRow[],int delCol[]){
    
    visited[row][col] = 1;

    int m = board.size();
    int n = board[0].size();
    //check for top,bottom,left,right
    for(int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
        && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow,ncol,board,visited,delRow,delCol);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    //travese first row
    for(int j=0; j<n; j++){
        if(board[0][j] == 'O'){
            dfs(0,j,board,visited,delRow,delCol);
        }
    }
    //travese last row
    for(int j=0; j<n; j++){
        if(board[m-1][j] == 'O'){
            dfs(m-1,j,board,visited,delRow,delCol);
        }
    }
    //travese first column
    for(int i=0; i<m; i++){
        if(board[i][0] == 'O'){
            dfs(i,0,board,visited,delRow,delCol);
        }
    }
    //travese last column
    for(int i=0; i<m; i++){
        if(board[i][n-1] == 'O'){
            dfs(i,n-1,board,visited,delRow,delCol);
        }
    }

    //replace 'O' with 'X' that are not marked visited
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    return 0;
}