#include<iostream>
#include<vector>
using namespace std;

// time = O(n! * n)
// space = O(n)

void printSolution(vector<vector<char>>& board,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl <<endl;
}
bool isSafe(int row,int col,vector<vector<char>>& board,int n){
    int i = row;
    int j = col;

    //check row
    while(j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }
    //check upper left diagonal
    i = row;
    j = col;
    while(i>=0 && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    //check lower left diagonal
    i = row;
    j = col;
    while(i < n && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solveProblem(vector<vector<char>>& board,int col,int n){
    //base case
    if(col >= n){
        printSolution(board,n);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row,col,board,n)){
            //place queen
            board[row][col] = 'Q';
            //recursive calls
            solveProblem(board,col+1,n);
            //backtrack
            board[row][col] = '-';
        }
    }
}
int main(){
    int n = 4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col = 0;
    // - empty cell
    // Q queen at that cell
    solveProblem(board,col,n);

    return 0;
}