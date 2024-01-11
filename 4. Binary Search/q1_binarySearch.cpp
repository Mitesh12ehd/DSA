#include<iostream>
using namespace std;

int binarySearch(int arr[],int key,int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;   // mid = (start+end)/2

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        else if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    int arr[] = {1,4,7,10,15,16,18,25,57,68,71};
    int key = 7;
    int index = binarySearch(arr,16,11);
    if(index == -1){
        cout<<"key not found";
    }
    else{
        cout<<"index = "<<index;
    }
    return 0;
}