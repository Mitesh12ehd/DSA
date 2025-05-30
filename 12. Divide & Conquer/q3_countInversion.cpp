#include<iostream>
#include<vector>
using namespace std;

//gfg
//count inversions

long countInversion(vector<int>& arr,int start,int end){
    int mid = (start+end) / 2;
    int i = start;
    int j = mid+1;
    long count = 0;

    while(i<=mid && j<=end){
        if(arr[i] > arr[j]){
            //if current elment of left array is inversion rest element of left array is
            //also inversion because rest element are greater,so calculate directly by formula
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
    long count = countInversion(arr,start,end);
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