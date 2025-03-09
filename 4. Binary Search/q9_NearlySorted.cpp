#include<iostream>
#include<vector>
using namespace std;

//defination of sorted array
//element that is placed on i'th index in sorted order,
//in nearly sorted array it find out on (i-1) or (i) or (i+1) index

int binarySearch(vector<int> arr,int key){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        else if(mid+1 <= arr.size() && arr[mid+1] == key){
            return mid+1;;
        }
        else if(mid-1 >= 0 && arr[mid-1] == key){
            return mid-1;;
        }
        else if(key < arr[mid]){
            //left search
            end = mid - 2;
            //mid-2 because mid-1 already checked
        }
        else{
            //right search
            start = mid + 2;
            //mid+2 because mid+1 already checked
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    vector<int> arr{10,3,40,20,50,80,70};
    int key = 80;
    int index = binarySearch(arr,key);

    if(index == -1){
        cout<<"key not found";
    }
    else{
        cout<<"index = "<<index;
    }

    return 0;
}