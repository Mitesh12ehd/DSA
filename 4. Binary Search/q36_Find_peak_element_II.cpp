#include<iostream>
#include<vector>
using namespace std;

//Leetcode 1901
//Find a peak element II

//brute force will be check for each element time = O(m*n*4)

//optimal approach

int findMaxElement(vector<vector<int>>& mat,int col){
    int m = mat.size();
    int n = mat[0].size();

    int maxEle = -1;
    int index = -1;
    for(int i=0; i<m; i++){
        if(mat[i][col] > maxEle){
            maxEle = mat[i][col];
            index = i;
        }
    } 
    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start+end)/2;
        int maxRowIndex = findMaxElement(mat,mid);

        int leftElement = (mid-1 >= 0) ? (mat[maxRowIndex][mid-1]) : (-1);
        int rightElement = (mid+1 < n) ? (mat[maxRowIndex][mid+1]) : (-1);

        if(mat[maxRowIndex][mid] > leftElement 
            && mat[maxRowIndex][mid] > rightElement){
            return {maxRowIndex,mid};
        }
        else if(mat[maxRowIndex][mid] < leftElement){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return {-1,-1};
}

int main(){
    return 0;
}