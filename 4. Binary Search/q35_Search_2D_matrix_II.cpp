#include<iostream>
#include<vector>
using namespace std;

//Leetcode 240
//Search a 2D matrix II   

//first solution will be check if element time = O(m*n)
//second solution will be apply binary search on each row time = O(m*logn)

//third solution time = O(m+n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n-1;

    while(row < m && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    return 0;
}