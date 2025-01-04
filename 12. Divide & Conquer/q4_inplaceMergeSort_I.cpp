#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void partition(vector<int>& arr,int start,int end){
    if(start >= end){
        return;
    }
    //step 1 - Choose Pivot
    int pivot = start;
    
    //step 2 - find right position for pivot element , place it here.
    int count = 0;
    for(int i=start+1; i<=end; i++){
        if(arr[i] <= arr[pivot]){
            count++;
        }
    }
    swap(arr[pivot],arr[start+count]);
    pivot = start + count;
    partition(arr,start,pivot-1);
    partition(arr,pivot+1,end);
}

void mergeTwoSortedArray(vector<int>& arr, int start, int end){
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;

    while(i <= mid){
        if(arr[i] <= arr[j]){
            i++;
        }
        else{
            swap(arr[i],arr[j]);
            //place j.th element to its right position using quick sort partition
            partition(arr,j,end);
        }
    }
}
void merge_sort(vector<int>& arr,int start,int end){
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
    vector<int> arr{5,1,1,2,0,0};

    int start = 0;
    int end = arr.size() - 1;
    merge_sort(arr,start,end);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}