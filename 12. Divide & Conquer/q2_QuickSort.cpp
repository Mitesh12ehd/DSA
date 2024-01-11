#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
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


    //step 3 - left of pivot is smaller,and right of pivot is greater.
    int i = start;
    int j = end;

    while( i<pivot && j>pivot){
        while(arr[i] <= arr[pivot]){
            i++;
        }
        while(arr[j] > arr[pivot]){
            j--;
        }
        if(i<pivot && j>pivot){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivot;
}
void quickSort(int arr[],int start,int end){
    //base case
    if(start >= end){
        return;
    }
    //partition , it return pivot Index;
    int pivot = partition(arr,start,end);
    //recursive calls
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}
int main(){
    int arr[23] = {10,9,8,7,6,5,4,3,2,1,1,1,1,1,1,2,2,5,6,7,8,9,10};
    int n = 23;
    int start = 0;
    int end = n-1;
    quickSort(arr,start,end);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}