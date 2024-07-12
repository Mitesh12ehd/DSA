#include<iostream>
#include<vector>
using namespace std;

// approach : how many swap require to convert given array to sorted array.

long mergeTwoSortedArray(vector<int>& arr, int start, int end){
    long count = 0;
    //step 1- create a two array
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftArray[len1];
    int rightArray[len2];

    int k = start;
    for(int i=0; i<len1; i++){
        leftArray[i] = arr[k];
        k++;
    }
    k = mid+1;
    for(int i=0; i<len2; i++){
        rightArray[i] = arr[k];
        k++;
    }

    //step 2 merge those two sorted array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while(leftIndex < len1 && rightIndex < len2){
        if(leftArray[leftIndex] <= rightArray[rightIndex]){
            arr[mainArrayIndex] = leftArray[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = rightArray[rightIndex];
            mainArrayIndex++;
            rightIndex++;
            count = count + (len1 - leftIndex);
        }
    }
    //if left array remaining direct push into array
    while(leftIndex < len1){
        arr[mainArrayIndex] = leftArray[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    //if right array remaining direct push into array
    while(rightIndex < len2){
        arr[mainArrayIndex] = rightArray[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    return count;
}
long merge_sort(vector<int>& arr,int start,int end){
    long count = 0;
    //base case
    // if s==e then single element
    // if s>e then invalid array
    if( start >= end){
        return 0;
    }

    int mid = (start+end) / 2;
    //call for left part
    count = count + merge_sort(arr,start,mid);
    //call for right part
    count = count + merge_sort(arr,mid+1,end);

    //merge two sorted array
    count = count + mergeTwoSortedArray(arr,start,end);

    return count;
}
//method 1
long countInversions(vector<int> arr) {
    long count = 0;
    count = merge_sort(arr,0,arr.size()-1);
    return count;
}
//method 2
// int countInversions(vector<int> arr){
//     int count = 0;
//     for(int i=0; i<arr.size(); i++){
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[i] >arr[j]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
int main(){
    //hackerrank
    vector<int> arr{8,4,2,1};
    cout << countInversions(arr);
    return 0;
}