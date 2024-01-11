#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&arr ,int start,int end,int key){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int expontialSearch(vector<int> &arr,int key){
    if(arr[0] == key){
        return 0;
    }
    int i=1;
    while(i<arr.size() && arr[i] <= key){
        i = i*2;
    }
    int start = i/2;
    int n = arr.size();
    int end = min(i,n-1);
    return binarySearch(arr, start, end, key);
}
int main(){
    vector<int> arr{3,4,5,6,11,13,14,15,56,70};
    int key = 13;
    cout<<expontialSearch(arr,key);

    return 0;
}