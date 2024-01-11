#include<iostream>
using namespace std;

int firstOccurence(int arr[],int key,int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;   // mid = (start+end)/2

    int index = -1;
    while(start<=end){
        if(arr[mid] == key){
            //store index and left part
            index = mid;
            end = mid-1;
        }
        else if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return index;
}

int main(){
    
    int arr[] = {1,3,4,4,4,4,5,6,6,6,7,7,7,9,9,10};
    int key = 7;
    int index = firstOccurence(arr,7,16);

    if(index == -1){
        cout<<"key not found";
    }
    else{
        cout<<"index = "<<index;
    }

    return 0;
}