#include<iostream>
#include<vector>
using namespace std;

//now this type of questions use concept of binary search on 2D array

//GFG
//Row with max 1s

//brute force time=O(m*n)
int rowWithMax1s(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    int row = -1;
    int maxCount = -1;

    for(int i=0; i<m; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }

        if(count != 0 && count > maxCount){
            maxCount = count;
            row = i;
        }
    }
    return row;
}

//optimal time = O(m*logn)
int rowWithMax1s(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    int maxCount = -1;
    int row = -1;
    
    for(int i=0; i<m; i++){
        int start = 0;
        int end = arr[i].size()-1;
        int index = n; //marked as n because if there is no one in whole row
                       // count becomes zero

        while(start<=end){
            int mid = (start+end)/2;
            if(arr[i][mid] == 1){
                index = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        int count = n - start;
        if(count > maxCount){
            maxCount = count;
            row = i;
        }
    }
    return row;
}

int main(){
    return 0;
}