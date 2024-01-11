#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        //row check
        if(board[row][i] == value)
            return false;
        
        //col check
        if(board[i][col] == value) 
            return false;
        //3*3 box check
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
            return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //check for empty cell
            if(board[i][j] == '.') {
                //try to fill with values ranging from 1 to 9
                for(char val = '1'; val<='9'; val++) {
                    //check for safety
                    if(isSafe(i,j, board, val)) {
                        //insert
                        board[i][j] = val;
                        //recursion sambal lega
                        bool remainingBoardSolution = solve(board);
                        if(remainingBoardSolution == true) {
                            return true;
                        }
                        else {
                            //backtrack
                            board[i][j] = '.';
                        }
                    }
                }
                //if 1 se 9 tak koi bhi value se solution
                //nahi nikla ,current cell pr, 
                //that means piche kahin pr galti h , 
                //go back by returning false
            return false;
            }
        }
    }
    //all cells filled 
    return true;
}
int main(){
    vector<vector<char>> sudoku_board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solve(sudoku_board);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku_board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}