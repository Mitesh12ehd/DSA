#include<iostream>
#include<vector>
#include<set>
using namespace std;

//leetcode 73
//set matrix zeros

//approach 1
//here brute force approach wiil be
//iterate whole matrix and if we find (row,col) = 0;
//mark whole row and col by itreting inside

//approach 2 using extra space
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    set<pair<int,int>> st; //1 : row
                           //0 : col
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                st.insert({i,true});
                st.insert({j,false});
            }
        }
    }
    for(auto it:st){
        if(it.second == 1){
            //row
            int row = it.first;
            for(int j=0; j<n; j++){
                matrix[row][j] = 0;
            }
        }
        else{
            int col = it.first;
            for(int i=0; i<m; i++){
                matrix[i][col] = 0;
            }
        }
    }
}

//optimal space approach
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    //int row[m] if row[i] == 0 then ith row contain 0
    //int col[n] if col[j] == 0 then jth col contain 0
    int col0 = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                //mark the ith row
                matrix[i][0] = 0;
                //mark the jth row
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] != 0){
                //check if row or col contain zeors
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //now convert first row
    if(matrix[0][0] == 0){
        for(int j=0; j<n; j++){
            matrix[0][j] = 0;
        }
    }
    //now convert first col
    if(col0 == 0){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    } 
}

int main(){
    

    return 0;
}