#include<iostream>
#include<vector>
using namespace std;

//leetcode 493
//Reverse pairs

//brute force time = O(n^2)
// int reversePairs(vector<int>& nums) {
//     int n = nums.size();
//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(nums[i] > 2 * nums[j]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

//optimal approach using merge sort
//time = O(nlogn) we just iterate once array in merge two array function,
//                so after this merge function takes O(n) time
//space = O(n) 

long countReversePair(vector<int>& nums,int start,int end){
    int mid = (start+end) / 2;
    int i = start;
    int j= mid+1;
    long count = 0;

    while(i<=mid && j<=end){
        long long temp1 = nums[i];
        long long temp2 = (long long) 2 * nums[j];
        if(temp1 > temp2){
            //if current elment of left array is reverse pair rest element of left array is
            //also reverse pair so calculate directly by formula
            //and now consider next element in rightarray
            count = count + (mid-i+1);
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}
long mergeTwoSortedArray(vector<int>& arr, int start, int end){
    long count = countReversePair(arr,start,end);
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
int reversePairs(vector<int>& nums) {
    long count = 0;
    count = merge_sort(nums,0,nums.size()-1);
    return count;
}

int main(){
    return 0;
}