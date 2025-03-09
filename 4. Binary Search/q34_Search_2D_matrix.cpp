#include<iostream>
#include<vector>
using namespace std;

//Leetcode 74
//Search a 2D matrix 

//first solution will be check if element time = O(m*n)
//second solution will be apply binary search on each row time = O(m*logn)

//third solution time = O(m + logn)
bool binarySearch(vector<int>& arr,int target){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i=0; i<m; i++){
        if(target >= matrix[i][0] && target <= matrix[i][n-1]){
            if(binarySearch(matrix[i],target)){
                return true;
            }
        }
    }
    return false;
}

//fourth solution time = O(log(m*n))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int start = 0;
    int end = (m*n) - 1;
    while(start <= end){
        int mid = (start+end) / 2;
        int row = mid / n;
        int col = mid % n;

        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}

int main(){
    return 0;
}