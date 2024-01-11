#include<iostream>
#include<vector>
using namespace std;

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