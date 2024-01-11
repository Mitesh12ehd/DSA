#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(arr[mid] < arr[mid+1]){
            //right part search
            start = mid+1;
        }
        else{
            //left part
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return end;
}
int main(){
    vector<int> arr{0,10,5,2};
    int peak_element = peakIndexInMountainArray(arr);
    cout<<"Peak Element at index = "<<peak_element;

    return 0;
}