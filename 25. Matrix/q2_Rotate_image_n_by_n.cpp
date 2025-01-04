#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//leetcode 46
//rotate_image of n*n size

//brute force
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> ans(n,vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int col = n-i-1;
            ans[j][col] = matrix[i][j];
        }
    }

    //just copy answer into orginal matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = ans[i][j];
        }
    }   
}

//in-place
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    //1.take a transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    //2.reverse each row
    for(int i=0; i<n; i++){
        int start = 0; 
        int end = n-1;
        while(start<=end){
            swap(matrix[i][start],matrix[i][end]);
            start++,end--;

        }
    }
}

int main(){
    return 0;
}