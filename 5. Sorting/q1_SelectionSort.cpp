#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    //Time = O(n^2)  Space = O(1) 
    for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}
int main(){
    vector<int> arr{11,25,12,22,64};
    selectionSort(arr,arr.size());
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}