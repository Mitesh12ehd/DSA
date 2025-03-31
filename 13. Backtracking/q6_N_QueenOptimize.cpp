#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// time = O(n!)
// space = O(4,n)

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;

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
    if(rowCheck[row] == true){
        return false;
    }
    if(upperLeftDiagonalCheck[n+1+col-row] == true){
        return false;
    }
    if(bottomLeftDiagonalCheck[row+col] == true){
        return false;
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
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n+1+col-row] = true;
            bottomLeftDiagonalCheck[row + col] = true;

            //recursive calls
            solveProblem(board,col+1,n);

            //backtracking
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n+1+col-row] = false;
            bottomLeftDiagonalCheck[row + col] = false;
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