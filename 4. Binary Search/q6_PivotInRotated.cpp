#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(start == end){
            return start;
        }
        else if( mid+1<=end && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if( mid-1>=start && arr[mid] < arr[mid-1]){
            return mid-1;
        }
        else if(arr[start] > arr[mid]){
            //left
            end = mid-1;
        }
        else{
            //right
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> arr{9,10,2,4,6,8};
    int pivot_element = findPivot(arr);
    cout<<"Pivot Element = "<<arr[pivot_element];

    return 0;
}