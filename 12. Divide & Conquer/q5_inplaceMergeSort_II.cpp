#include<iostream>
#include<vector>
using namespace std;

void mergeTwoSortedArray(vector<int> &arr, int start, int end){
    int total_length = end - start + 1;
    int gap = (total_length/2) + (total_length%2); //ceil function
    while(gap > 0){
        int i = start;
        int j = start+gap;
        while(j <= end){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;
        }
        if(gap <= 1){
            gap = 0;
        }
        else{
            gap = (gap/2) + (gap%2);
        }
    }
}
void merge_sort(vector<int> &arr,int start,int end){
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
    vector<int> arr{1,1,2,3,5,7,8,4,1,2,3,6};
    int start = 0;
    int end = arr.size()-1;
    merge_sort(arr,start,end);
    for(auto it:arr){
        cout << it << " ";
    }
    return 0;
}