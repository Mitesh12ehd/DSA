#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//GFG
//Median in row-wise sorted matrix

//brute force time = O(m*n log(m*n)  + m*n)
//1.store all element in one new array
//2.sort array
//3.return arr[arr.size()/2]

//optimal time = O( log(max-min) * log(m*logn) )
//dryrun on [1,3,5]
//          [2,6,9]
//          [3,6,9]

//dryrun on [1,5,7,9,11]
//          [2,3,4,5,10]
//          [9,10,12,14,16]

//take more example on your own to understand and dryrun on it

/*
it return index where element at index in just larger than given element
i.e. it return counts of elments who are <= given element
*/
int upperBound(vector<int>& arr,int element){
    int start = 0;
    int end = arr.size()-1;
    int ans = arr.size();

    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] > element){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return start;
}

int countSmallEqual(vector<vector<int>> &mat,int element){
    int m = mat.size();
    int n = mat[0].size();

    int count = 0;
    for(int i=0; i<m; i++){
        count = count + upperBound(mat[i],element);
    }
    return count;
}

int median(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    int start = INT_MAX;
    int end = INT_MIN;
    for(int i=0; i<m; i++){
        start = min(start,mat[i][0]);
        end = max(end,mat[i][n-1]);
    }

    int requiredElements = (m*n)/ 2;
    while(start <= end){
        int mid = (start + end) / 2;
        int smallEqualElements = countSmallEqual(mat,mid);
        if(smallEqualElements <= requiredElements){
            //mid element can't be median
            //because it doesn't have more than (m*n / 2) who are <= mid
            start = mid+1;
        }
        else{
            //mid element can be median
            //because it have more than (m*n / 2) who are <= mid
            end = mid-1;
        }
    }
    return start;
}

int main(){
    return 0;
}