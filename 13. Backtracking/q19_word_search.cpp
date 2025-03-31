#include<iostream>
#include<vector>
using namespace std;

//Leetcode 79
//Word search

//time = O(m*n*4^l)  where  L=str.length()
//space = O(m*n)

vector<int> dRow = {0,-1,0,1};
vector<int> dCol = {-1,0,1,0};
bool helper(int i,int j,int index,vector<vector<char>>& board,
            vector<vector<int>>& visited,string& word){
    int m = board.size();
    int n = board[0].size();            

    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] 
        || board[i][j] != word[index]){
        return false;
    }
    if(index == word.length()-1){
        return true;
    }
    
    visited[i][j] = 1;
    for(int x=0; x<4; x++){
        int nrow = i + dRow[x];
        int ncol = j + dCol[x];

        if(helper(nrow,ncol,index+1,board,visited,word)){
            return true;
        }
    }
    visited[i][j] = 0;
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == word[0]){
                if(helper(i,j,0,board,visited,word)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    return 0;
}