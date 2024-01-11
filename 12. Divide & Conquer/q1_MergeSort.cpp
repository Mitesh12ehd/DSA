#include<iostream>
using namespace std;

void mergeTwoSortedArray(int arr[], int start, int end){
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
}
void merge_sort(int arr[],int start,int end){
    //base case
    // if s==e then single element
    // if s>e then invalid array
    if( start >= end){
        return;
    }

    int mid = (start+end) / 2;
    //call for left part
    merge_sort(arr,start,mid);
    //call for right part
    merge_sort(arr,mid+1,end);

    //merge two sorted array
    mergeTwoSortedArray(arr,start,end);
}
int main(){
    int arr[] = {1,1,2,3,5,7,8,4,1,2,3,6};
    int n = 12;

    int start = 0;
    int end = n - 1;
    merge_sort(arr,start,end);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}