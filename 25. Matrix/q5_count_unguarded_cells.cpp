#include<iostream>
#include<vector>
using namespace std;

//leetcode 2257
//count unguarded cells in the grid

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> matrix(m,vector<int>(n,0));
    //mark walls as 1
    //mark gaurd as 2
    //mark empty cell as 0
    for(auto it:guards){
        int row=it[0];
        int col=it[1];
        matrix[row][col] = 2;
        visited[row][col] = true;
    }
    for(auto it:walls){
        int row=it[0];
        int col=it[1];
        matrix[row][col] = 1;
        visited[row][col] = true;
    }

    //expand gaurd in all four direction
    for(auto it:guards){
        int row = it[0];
        int col = it[1];  

        //expand in left
        for(int var=col-1; var>=0; var--){
            if(matrix[row][var] != 0){
                break;
            }
            visited[row][var] = true;
        }
        //expand in right
        for(int var=col+1; var<n; var++){
            if(matrix[row][var] != 0){
                break;
            }
            visited[row][var] = true;
        }
        //expand in top
        for(int var=row-1; var>=0; var--){
            if(matrix[var][col] != 0){
                break;
            }
            visited[var][col] = true;
        }
        //expand in bottom
        for(int var=row+1; var<m; var++){
            if(matrix[var][col] != 0){
                break;
            }
            visited[var][col] = true;
        }     
    }
        
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    

    return 0;
}