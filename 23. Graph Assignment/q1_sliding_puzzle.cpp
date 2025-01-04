#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

//leetcode 773
//sliding puzzle

class qData{
    public:
    int r;
    int c;
    vector<vector<int>> currentBoard;//indicate current board
    int steps;
};

int slidingPuzzle(vector<vector<int>>& board) {
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    vector<vector<int>> result = {{1,2,3},{4,5,0}};

    qData obj;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 0){
                obj.r = i;
                obj.c = j;
                break;
            }
        }
    }
    obj.currentBoard = board;
    obj.steps = 0;

    queue<qData> q;
    q.push(obj);
    map<vector<vector<int>>,int> mp;
    mp[board]++;

    while(!q.empty()){
        int row = q.front().r;
        int col = q.front().c;
        int steps = q.front().steps;
        vector<vector<int>> v = q.front().currentBoard;

        if(v == result){
            return steps;
        }
        q.pop();

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<2 && ncol>=0 && ncol<3){
                swap(v[nrow][ncol],v[row][col]);
                if(mp.find(v) == mp.end()){
                    qData obj1;
                    obj1.r = nrow;
                    obj1.c = ncol;
                    obj1.currentBoard = v;
                    obj1.steps = steps+1;
                    q.push(obj1);
                    mp[v]++;
                }
                swap(v[nrow][ncol],v[row][col]);
            }
        }
    }
    return -1;
}

int main(){
    return 0;
}