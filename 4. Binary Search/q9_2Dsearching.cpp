#include<iostream>
using namespace std;
bool binarySearch(int arr[][4],int rows, int columns,int target){
    int start = 0;
    int end = (rows*columns) - 1;
    int mid = start + (end-start) / 2;

    while(start<=end){
        int rowIndex = mid / columns;
        int columnIndex = mid % columns;

        if(arr[rowIndex][columnIndex] == target){
            cout<<"Found at = "<<rowIndex<<" "<<columnIndex;
            return true;
        }
        else if(arr[rowIndex][columnIndex] < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start) / 2;
    }
    return false;
}
int main(){
    int arr[5][4] = { {1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12},
                      {13,14,15,16} };
    int rows = 5;
    int columns = 4;

    int target = 15;
    bool ans = binarySearch(arr,rows,columns,target);
    cout<<endl;
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}